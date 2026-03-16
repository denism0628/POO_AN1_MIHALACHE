#pragma once
#include <initializer_list>
#include <string>
class Sort
{
    private:
    int* v;
    int count;

    void QuickSortRec(int min,int max,bool ascendent);

public:
    // add constuctors
    Sort(int count,int min,int max);
    Sort(std::initializer_list<int>list);
    Sort(int* vector,int count);
    Sort(int count,...);
    Sort(std::string s);

    ~Sort();

    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};