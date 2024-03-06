#pragma once
#include <string>
class Student
{
    std::string name;
    float gradeMath;
    float gradeEnglish;
    float gradeHistory;

public:
    void SetName(const std::string& name);
    std::string GetName() const;
    void SetGradeMath(float grade);
    float GetGradeMath() const;
    void SetGradeEnglish(float grade);
    float GetGradeEnglish() const;
    void SetGradeHistory(float grade);
    float GetGradeHistory() const;
    float GetGradeAverage() const;
};

int CompareByName(const Student& student1, const Student& student2);
int CompareByMathGrade(const Student& student1, const Student& student2);
int CompareByEnglishGrade(const Student& student1, const Student& student2);
int CompareByHistoryGrade(const Student& student1, const Student& student2);
int CompareByAverage(const Student& student1, const Student& student2);