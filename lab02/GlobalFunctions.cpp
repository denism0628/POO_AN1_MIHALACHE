#include "GlobalFunctions.h"

int CompareByName(const Student &s1,const Student &s2){
    if(s1.getName()==s2.getName()) return 0;
    if(s1.getName()>s2.getName()) return 1;
    return -1;
}

int CompareByMath(const Student &s1,const Student &s2){
    if(s1.getMathGrade()==s2.getMathGrade()) return 0;
    if(s1.getMathGrade()>s2.getMathGrade()) return 1;
    return -1;
}

int CompareByEnglish(const Student &s1,const Student &s2){
    if(s1.getEnglishGrade()==s2.getEnglishGrade()) return 0;
    if(s1.getEnglishGrade()>s2.getEnglishGrade()) return 1;
    return -1;
}

int CompareByHistory(const Student &s1,const Student &s2){
    if(s1.getHistoryGrade()==s2.getHistoryGrade()) return 0;
    if(s1.getHistoryGrade()>s2.getHistoryGrade()) return 1;
    return -1;
}

int CompareByAverage(const Student &s1,const Student &s2){
    if(s1.AverageGrade()==s2.AverageGrade()) return 0;
    if(s1.AverageGrade()>s2.AverageGrade()) return 1;
    return -1;
}