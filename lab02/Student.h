#pragma once
#define STUDENT_H
#include<string>

class Student
{
    private:
    std::string name;
    float mathgrade;
    float englishgrade;
    float historygrade;

    public:
    void setName(const std::string &studentName);
    std::string getName() const;

    void setMathGrade(float grade);
    float getMathGrade() const;

    void setEnglishGrade(float grade);
    float getEnglishGrade() const;

    void setHistoryGrade(float grade);
    float getHistoryGrade() const;

    float AverageGrade() const;

};