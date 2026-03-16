#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

Sort::Sort(int count,int min,int max){
    this->count=count;
    this->v=new int[count];
    for(int i=0;i<count;i++)
       this->v[i]=min+rand()%(max-min+1);

}

Sort::Sort(std::initializer_list<int>list){
    this->count=list.size();
    this->v=new int[this->count];
    int i=0;
    for(int val : list)
        this->v[i++]=val;
}

Sort::Sort(int* vector,int count){
    this->count=count;
    this->v=new int[count];
    for(int i=0;i<count;i++)
       this->v[i]=vector[i];
}

Sort::Sort(int count,...){
    this->count=count;
    this->v=new int[count];
    va_list args;
    va_start(args,count);

    for(int i=0;i<count;i++)
      this->v[i]=va_arg(args,int);

    va_end(args);
}

Sort::Sort(std::string s){
    this->count=std::count(s.begin(),s.end(),',')+1;
    this->v=new int[this->count];
    
    std::stringstream ss(s);
    std::string nr;
    int i=0;

    while(std::getline(ss,nr,','))
       this->v[i++]=std::stoi(nr);
}

Sort::~Sort(){
    delete[] v;
}

void Sort::InsertSort(bool ascendent){
    for(int i=1;i<count;i++){
        int x=v[i];
        int j=i-1;
        if(ascendent){
            while(j>=0 && v[j]>x){
                v[j+1]=v[j];
                j=j-1;
            }
        } 
        else
        {
            while(j>=0 && v[j]<x){
                v[j+1]=v[j];
                j=j-1;
            }
        }
    v[j+1]=x;
    }
}

void Sort::BubbleSort(bool ascendent){
    bool ok;
    for(int i=0;i<count-1;i++){
        ok=false;
        for(int j=0;j<count-i-1;j++){
            bool condition=ascendent ? (v[j]>v[j+1]) : (v[j]<v[j+1]);
            if(condition){
                int aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                ok=true;
            }
        }
    if(!ok) break;
    }
}

void Sort::QuickSortRec(int min, int max, bool ascendent) {
    int i=min;
    int j=max;
    int pivot=v[(min+max)/2];

    while (i<=j) {
        if (ascendent) {
            while (v[i]<pivot) i++;
            while (v[j]>pivot) j--;
        } else {
            while (v[i]>pivot) i++;
            while (v[j]<pivot) j--;
        }

        if (i<=j) {
            int aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
    }

    if (min<j) {
        QuickSortRec(min,j,ascendent);
    }
    if (i<max) {
        QuickSortRec(i,max,ascendent);
    }
}

void Sort::QuickSort(bool ascendent){
    QuickSortRec(0,count-1,ascendent);
}

void Sort::Print(){
    for(int i=0;i<count;i++)
       std::cout<<v[i]<<' ';
    std::cout<<'\n';
}

int Sort::GetElementsCount(){
    return count;
}

int Sort::GetElementFromIndex(int index){
    if(index>=0 && index<count)
       return v[index];
    return -1;
}