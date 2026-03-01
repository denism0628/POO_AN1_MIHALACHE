#include "Student.h"
#include <iostream>

void Student::setName(const std::string &studentName){
    name=studentName;
}

std::string Student::getName() const{
     return name;
}

void Student::setMathGrade(float grade){
    if(grade>=1.0f && grade<=10.0f)
        mathgrade=grade;
}

float Student::getMathGrade() const{
    return mathgrade;
}


void Student::setEnglishGrade(float grade){
    if(grade>=1.0f && grade<=10.0f)
        englishgrade=grade;
}

float Student::getEnglishGrade() const{
    return englishgrade;
}


void Student::setHistoryGrade(float grade){
    if(grade>=1.0f && grade<=10.0f)
        historygrade=grade;
}

float Student::getHistoryGrade() const{
    return historygrade;
}

float Student::AverageGrade() const{
    return (mathgrade+historygrade+englishgrade)/3.0f;
}