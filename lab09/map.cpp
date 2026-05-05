#include <iostream>

using namespace std;

template <typename K,typename V>

class Map{

    private:
    struct Node{
        K key;
        V value;
    };
    Node* info;//pointer catre un vector de tip node alocat dinamic
    int len;
    int cnt;

    void resize(){
        len*=2;
        Node* newinfo=new Node[len];
        for(int i=0;i<cnt;i++)
            newinfo[i]=info[i];
        delete[] info;
        info=newinfo;
    }

    public:
    struct element{ //structured binding
        K key;
        V value;
        int index;
    };

    class Iterator{

        private:
            Node* ptr;
            int idx;

        public:
            Iterator(Node* p,int i):ptr(p),idx(i){}
            
            bool operator!=(const Iterator& other) const{
                return idx!=other.idx;
            }
            void operator++(){
                idx++;
            }
            element operator*() const{
                return{ptr[idx].key,ptr[idx].value,idx};
            }
    };


    Map(){
        len=10;
        cnt=0;
        info=new Node[len];
    }
    ~Map(){
        delete[] info;
    }

    V& operator[](const K& key){
        for(int i=0;i<cnt;i++)
            if(info[i].key==key)
                return info[i].value;
        if(cnt>=len)
            resize();
        info[cnt].key=key;
        return info[cnt++].value;
    }

    void Set(const K& key, V& value){
        (*this)[key]=value;
    }

    bool Get(const K& key,V& value) const{
        for(int i=0;i<cnt;i++)
            if(info[i].key==key){
                value=info[i].value;
                return true;
            }
        return false;
    }

    int Count() const{
        return cnt;
    }
    void Clear(){
        cnt=0;
    }

    bool Delete(const K& key){
        for(int i=0;i<cnt;i++){
            if(info[i].key==key){
                for(int j=i;j<cnt-1;j++)
                    info[j]=info[j+1];
                cnt--;
                return true;
            }
            
        }
        return false;
    }

    bool Includes(const Map<K,V>&other) const{
        for(int i=0;i<other.cnt;i++){
            bool gasit=false;
            for(int j=0;j<cnt;j++){
                if(info[j].key==other.info[i].key){
                    gasit=true;
                    break;
                }
            }
            if(!gasit) return false;
        }
        return true;
    }

    Iterator begin(){
        return Iterator(info,0);
    }
    Iterator end(){
        return Iterator(info,cnt);
    }
};


int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
