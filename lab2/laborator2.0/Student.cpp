#include "Student.h"

void Student::SetName(const std::string& name)
{
    this->name = name;
}

std::string Student::GetName() const
{
    return name;
}

void Student::SetGradeMath(float grade)
{
    gradeMath = grade;
}

float Student::GetGradeMath() const
{
    return gradeMath;
}

void Student::SetGradeEnglish(float grade)
{
    gradeEnglish = grade;
}

float Student::GetGradeEnglish() const
{
    return gradeEnglish;
}

void Student::SetGradeHistory(float grade)
{
    gradeHistory = grade;
}

float Student::GetGradeHistory() const
{
    return gradeHistory;
}

float Student::GetGradeAverage() const
{
    return (gradeMath + gradeEnglish + gradeHistory) / 3.0;
}

int CompareByName(const Student& student1, const Student& student2)
{
    return student1.GetName().compare(student2.GetName());
}

int CompareByMathGrade(const Student& student1, const Student& student2)
{
    if (student1.GetGradeMath() == student2.GetGradeMath())
    {
        return 0;
    }
    else if (student1.GetGradeMath() > student2.GetGradeMath())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int CompareByEnglishGrade(const Student& student1, const Student& student2)
{
    if (student1.GetGradeEnglish() == student2.GetGradeEnglish())
    {
        return 0;
    }
    else if (student1.GetGradeEnglish() > student2.GetGradeEnglish())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int CompareByHistoryGrade(const Student& student1, const Student& student2)
{
    if (student1.GetGradeHistory() == student2.GetGradeHistory())
    {
        return 0;
    }
    else if (student1.GetGradeHistory() > student2.GetGradeHistory())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


int CompareByAverage(const Student& student1, const Student& student2)
{
    if (student1.GetGradeAverage() == student2.GetGradeAverage())
    {
        return 0;
    }
    else if (student1.GetGradeAverage() > student2.GetGradeAverage())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}