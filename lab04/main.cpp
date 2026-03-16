#include <iostream>
#include "Sort.h"

int main()
{
    Sort s1(7,10,50);
    s1.BubbleSort(true);
    s1.Print();

    Sort s2({5,8,2,3,9});
    s2.InsertSort(false);
    s2.Print();

    int x[]={15,22,7,19,64};
    Sort s3(x,5);
    s3.QuickSort(true);
    s3.Print();

    Sort s4(6,99,72,15,19,23,10);
    s4.InsertSort(false);
    s4.Print();

    Sort s5("10,40,100,5,70");
    s5.BubbleSort(true);
    s5.Print();

    std::cout<<s5.GetElementsCount()<<'\n';
    std::cout<<s5.GetElementFromIndex(5);

    return 0;
}