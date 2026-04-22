#include <iostream>

template <typename T>
class Tree{
    public:
    struct Node{
        T value;
        Node* parinte;
        Node** copii;
        size_t nr_copii;
        size_t n;
        Node(T val,Node* p=nullptr) : value(val),parinte(p),nr_copii(0),n(2){
            copii=new Node*[n];
        }
        ~Node(){
            delete[] copii;
        }
    };
    

    private:
    Node* rad;

    void destroy_subtree(Node* node){
        if(!node) return;
        for(size_t i=0;i<node->nr_copii;i++)
           destroy_subtree(node->copii[i]);
        delete node;
    }

    Node* find_recursive(Node* current, T param, bool (*comp)(const T&, const T&)){
        if(!current) return nullptr;
        if(comp(param, current->value)) return current;
        for(size_t i=0;i<current->nr_copii;i++){
            Node* result=find_recursive(current->copii[i], param, comp);
            if(result) return result;
        }
        return nullptr;
    }

    size_t count_recursive(Node* current){
        if(!current) return 0;
        size_t total=1;
        for(size_t i=0;i<current->nr_copii;i++)
            total+=count_recursive(current->copii[i]);
    
        return total;
    }


    public:
        Tree(): rad(nullptr){}
        ~Tree() {
            destroy_subtree(rad);
        }

        Node* add_node(Node* parinte,T value){
            Node* newNode=new Node(value,parinte);
            if(parinte==nullptr){
                if(rad) destroy_subtree(rad);
                rad=newNode;
            }
            else{
                if(parinte->nr_copii==parinte->n){
                    parinte->n*=2;
                    Node** new_copii=new Node*[parinte->n];
                    for(size_t i=0;i<parinte->nr_copii;i++)
                        new_copii[i]=parinte->copii[i];
                    delete[] parinte->copii;
                    parinte->copii=new_copii;
                }
                parinte->copii[parinte->nr_copii++]=newNode;
            }
            return newNode;
        }


        Node* get_node(Node* parinte,size_t index=0){
            if(parinte==nullptr) return rad;
            if(index<parinte->nr_copii) return parinte->copii[index];
            return nullptr;
        }

        Node* insert(Node* parinte, size_t index, T value){
            if(parinte==nullptr) return add_node(nullptr, value);
            
            Node* newNode=new Node(value, parinte);
            if(index>parinte->nr_copii) index=parinte->nr_copii;

            if(parinte->nr_copii==parinte->n) {
                parinte->n *= 2;
                Node** new_copii=new Node*[parinte->n];
                for (size_t i=0;i<parinte->nr_copii;i++) {
                    new_copii[i]=parinte->copii[i];
                }
                delete[] parinte->copii;
                parinte->copii=new_copii;
            }

            for(size_t i=parinte->nr_copii;i>index;i--) {
                parinte->copii[i] = parinte->copii[i-1];
            }
            parinte->copii[index]=newNode;
            parinte->nr_copii++;

            return newNode;
        }

        void delete_node(Node* target){
            if(!target) return;

            if(target->parinte){
                Node* p=target->parinte;
                for(size_t i=0;i<p->nr_copii;i++){
                    if(p->copii[i]==target){
                        for(size_t j=i;j<p->nr_copii-1;j++)
                            p->copii[j]=p->copii[j+1];
                        p->nr_copii--;
                        break;
                    }
                }
            }
            else if(target==rad) rad=nullptr;
            
            destroy_subtree(target);
        }


        Node* find(T param, bool (*comp)(const T&, const T&)){
                return find_recursive(rad,param,comp);
        }


        void sort(Node* parinte,bool(*comp)(const T&,const T&)=nullptr){
            if(!parinte || parinte->nr_copii<2) return;
            for (size_t i=0;i<parinte->nr_copii-1;i++){
            for (size_t j=0;j<parinte->nr_copii-i-1;j++){
                bool ok = comp ? comp(parinte->copii[j+1]->value, parinte->copii[j]->value)
                                        : (parinte->copii[j+1]->value < parinte->copii[j]->value);
                if (ok){
                    Node* aux=parinte->copii[j];
                    parinte->copii[j]=parinte->copii[j+1];
                    parinte->copii[j+1]=aux;
                }
            }
        }
        }


        size_t count(Node* start=nullptr){
        if(start==nullptr){
            if(!rad) return 0;
            return count_recursive(rad)-1; 
        }
        return count_recursive(start)-1;
    }
};

bool compara_valori(const int& param, const int& valoare_din_nod){
    return param==valoare_din_nod;
}

bool sortare_descrescatoare(const int& a, const int& b){
    return a>b; 
}

bool cmp(const int& a, const int& b) {
    return a == b;
}


int main() {
    Tree<int> t;

    auto rad = t.add_node(nullptr, 10);
    
    auto c1 = t.add_node(rad, 20);
    t.add_node(rad, 30);
    t.add_node(c1, 40);

    t.insert(rad, 0, 15);
    
    t.sort(rad);

    std::cout << t.count() << "\n";

    auto gasit = t.find(40, cmp);
    if (gasit) {
        std::cout << gasit->value << "\n";
    }

    t.delete_node(c1);

    std::cout << t.count() << "\n";

    return 0;
}