#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

struct comp{
    bool operator()(const std::pair<std::string,int>&a,const std::pair<std::string, int>& b) const{
        if(a.second!=b.second)
            return a.second<b.second;

        return a.first>b.first;
    }
};

int main()
{
    std::ifstream inputFile("input.txt");
    std::string text ((std::istreambuf_iterator<char>(inputFile)),std::istreambuf_iterator<char>());
    inputFile.close();

    std::string s=" ,?!.";
    std::map<std::string,int>count;
    size_t start=text.find_first_not_of(s);

    while(start!=std::string::npos){
        size_t end=text.find_first_of(s,start);
        std::string word=text.substr(start,end-start);

        for(auto& c:word)
            c=std::tolower(static_cast<unsigned char>(c));
        count[word]++;

        start=text.find_first_not_of(s,end);
    }
    

    std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,comp>sortedWords;

    for(const auto& pair:count)
        sortedWords.push(pair);

    while(!sortedWords.empty()){
        std::pair<std::string,int> top=sortedWords.top();
        std::cout<<top.first<<"=>"<<top.second<<std::endl;
        sortedWords.pop();
    }

    return 0;
}