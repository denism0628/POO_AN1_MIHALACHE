#include <iostream>
#include "NumberList.h"
#include "Student.h"
#include "GlobalFunctions.h"
int main()
{
    ///1
    /*NumberList myList;

    myList.Init();

    myList.Add(15);
    myList.Add(26);
    myList.Add(13);
    myList.Add(9);
    myList.Add(18);
    myList.Add(21);

    myList.Sort();

    myList.Print();*/

    ///2
    Student s1,s2;

    s1.setName("Denis");
    s1.setEnglishGrade(8.5f);
    s1.setHistoryGrade(8.0f);
    s1.setMathGrade(9.0f);

    s2.setName("Andrei");
    s2.setEnglishGrade(9.5f);
    s2.setHistoryGrade(7.5f);
    s2.setMathGrade(7.0f);

    std::cout<<s1.AverageGrade()<<std::endl;
    std::cout<<s2.AverageGrade()<<std::endl;

    std::cout<<CompareByAverage(s1,s2)<<std::endl;
    std::cout<<CompareByHistory(s1,s2)<<std::endl;
    std::cout<<CompareByMath(s1,s2)<<std::endl;
    std::cout<<CompareByEnglish(s1,s2)<<std::endl;
    std::cout<<CompareByName(s1,s2)<<std::endl;

    return 0;

}