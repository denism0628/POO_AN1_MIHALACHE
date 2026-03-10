#include <iostream>
#include "Math.h"
#include "Canvas.h"
int main()
{
    /*std::cout<<Math::Add(3,7)<<"\n";
    std::cout<<Math::Add(1,2,3)<<"\n";
    std::cout<<Math::Add(5.2,6.3)<<"\n";
    std::cout<<Math::Add(1.2,2.6,3.8)<<"\n";
    std::cout<<Math::Mul(7,8)<<"\n";
    std::cout<<Math::Mul(7,8,9)<<"\n";
    std::cout<<Math::Mul(2.5,4.0)<<"\n";
    std::cout<<Math::Mul(1.3,3.0,9.5)<<"\n";
    std::cout<<Math::Add(4,10,5,20,15)<<"\n";

    const char* s1="Hello";
    const char* s2="World!";
    const char* aux=Math::Add(s1,s2);
    if(aux!=nullptr){
       std::cout<<"("<<s1<<"+"<<s2<<")"<<"="<<aux<<"\n";
       delete[] aux;
    }

    char* nullTest=Math::Add("OOP",nullptr);
    if(nullTest==nullptr)
       std::cout<<"da";*/


    ///2
    Canvas c(50,30);
    c.SetPoint(2,2,'P');
    c.DrawLine(5,5,20,10,'*');
    c.DrawRect(25,2,45,10,'#');
    c.FillRect(27,4,43,8,'@');
    c.DrawCircle(10,20,6,'O');
    c.FillCircle(35,20,5,'X');
    c.Print();

    c.Clear();
    c.Print();
    
    return 0;
}

