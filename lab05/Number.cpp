#include "Number.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int ChartoInt(char c){
    if (c>='0' && c<='9') return c-'0';
    if (c>='A' && c<='F') return c-'A'+10;
    if (c>='a' && c<='f') return c-'a'+10;
    return 0;
}

char InttoChar(int n){
    if (n>=0 && n<=9) return (char)(n+'0');
    return (char)(n-10+'A');
}

long long Number::convertToBase10() const{
    long long res=0;
    int l=GetDigitsCount();
    for(int i=0;i<l;i++)
       res+=ChartoInt(value[i])*pow(base,l-i-1);
    return res;
}


void Number::convertFromBase10(long long val, int targetBase){
    if (val==0) {
        delete[] value;
        value=new char[2];
        value[0]='0';
        value[1]='\0';
        base=targetBase;
        return;
    }

    char aux[100];
    int idx=0;
    while (val>0) {
        aux[idx++]=InttoChar(val % targetBase);
        val/=targetBase;
    }
    
    delete[] value;
    value=new char[idx+1];
    for (int i=0;i<idx;i++)
        value[i]=aux[idx-1-i]; // Reverse the string

    value[idx]='\0';
    base=targetBase;
}


Number::Number(const char*value,int base){
    this->base=base;
    if(value){
        this->value=new char[strlen(value)+1];
        strcpy(this->value,value);
    }
    else{
        this->value=new char[1];
        this->value[0]='\0';
    }
}

Number::Number(int val){
    base=10;
    value=nullptr;
    convertFromBase10(val,10);
}

Number::~Number(){
    delete[] value;
}

Number::Number(const Number& other){
        base=other.base;
        value=new char[strlen(other.value)+1];
        strcpy(value,other.value);
}

Number::Number(Number&& other){
    base=other.base;
    value=other.value;
    other.value=nullptr;
    other.base=10;
}

Number& Number::operator=(const Number& other){
    if(this!=&other){
        delete[] value;
        base=other.base;
        value=new char[strlen(other.value)+1];
        strcpy(value,other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other){
    if(this!=&other){
        delete[] value;
        base=other.base;
        value=other.value;
        other.value=nullptr;
        other.base=10;
    }
    return *this;
}

Number& Number::operator=(int val){
    convertFromBase10(val,this->base);
    return *this;
}

Number& Number::operator=(const char* val){
    delete[] value;
    if(val){
        value=new char[strlen(val)+1];
        strcpy(value,val);
    }
    else{
        value=new char[1];
        value[0]='\0';
    }
    return *this;
}

Number operator+(const Number& n1,const Number& n2){
    int maxBase=std::max(n1.base,n2.base);
    long long val1=n1.convertToBase10();
    long long val2=n2.convertToBase10();

    Number res("0",maxBase);
    res.convertFromBase10(val1+val2,maxBase);
    return res;
}

Number operator-(const Number& n1,const Number& n2){
    int maxBase=std::max(n1.base,n2.base);
    long long val1=n1.convertToBase10();
    long long val2=n2.convertToBase10();
    long long dif=val1-val2;
    if(dif<0) dif=0;

    Number res("0",maxBase);
    res.convertFromBase10(dif,maxBase);
    return res;
}

Number& Number::operator+=(const Number& other){
    long long val1=convertToBase10();
    long long val2=other.convertToBase10();
    int otherbase=std::max(this->base,other.base);

    convertFromBase10(val1+val2,otherbase);
    return *this;
}

char Number::operator[](int index) const{
    if(index>=0 && index<GetDigitsCount())
       return value[index];
    return '\0';
}

bool Number::operator>(const Number& other) const{
    return this->convertToBase10()>other.convertToBase10();
}

bool Number::operator<(const Number& other) const{
    return this->convertToBase10()<other.convertToBase10();
}

bool Number::operator>=(const Number& other) const{
    return this->convertToBase10()>=other.convertToBase10();
}

bool Number::operator<=(const Number& other) const{
    return this->convertToBase10()<=other.convertToBase10();
}

bool Number::operator==(const Number& other) const{
    return this->convertToBase10()==other.convertToBase10();
}

bool Number::operator!=(const Number& other) const{
    return this->convertToBase10()!=other.convertToBase10();
}

Number& Number::operator--(){
    int l=GetDigitsCount();
    if(l<=1){
        delete[] value;
        value=new char[2];
        value[0]='0';
        value[1]='\0';
    }
    else{
        char* Newvalue=new char[l];
        strcpy(Newvalue,value+1);
        delete[] value;
        value=Newvalue;
    }
    return *this;
}

Number Number::operator--(int){
    Number aux(*this);
    int l=GetDigitsCount();
    if(l<=1){
        delete[] value;
        value=new char[2];
        value[0]='0';
        value[1]='\0';
    }
    else{
        value[l-1]='\0';
    }
    return aux;
}

void Number::SwitchBase(int newBase){
    if(base==newBase) return;
    long long val=convertToBase10();
    convertFromBase10(val,newBase);
}

void Number::Print() const{
    if(value)
        std::cout<<value<<'\n';
}

int Number::GetDigitsCount() const{
    if(value)
       return strlen(value);
    return 0;
}

int Number::GetBase() const{
    return base;
}