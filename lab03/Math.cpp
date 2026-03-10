#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int a,int b){
    return a+b;
}

int Math::Add(int a,int b,int c){
    return a+b+c;
}

int Math::Add(double a,double b){
    return (int)(a+b);
}

int Math::Add(double a,double b,double c){
    return (int)(a+b+c);
}

int Math::Mul(int a,int b){
    return a*b;
}

int Math::Mul(int a,int b,int c){
    return a*b*c;
}

int Math::Mul(double a,double b){
    return (int)(a*b);
}

int Math::Mul(double a,double b,double c){
    return (int)(a*b*c);
}

int Math::Add(int count,...){
     va_list args;
     va_start(args,count);

     int s=0;
     for(int i=0;i<count;i++)
        s+=va_arg(args,int);

    va_end(args);
    return s;
}

char* Math::Add(const char* s1,const char* s2){
     if(s1==nullptr||s2==nullptr)
        return nullptr;

    size_t l1=strlen(s1);
    size_t l2=strlen(s2);
    char* rez=new char[l1+l2+1];

    strcpy(rez,s1);
    strcat(rez,s2);

    return rez;
}