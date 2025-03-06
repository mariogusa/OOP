#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    float mathGrade;
    float englishGrade;
    float historyGrade;
public:
    Student();
    Student(const std::string &name, float mathGrade, float englishGrade, float historyGrade);
    
    void setName(const std::string &name);
    std::string getName() const;
    
    bool setMathGrade(float grade);
    float getMathGrade() const;
    
    bool setEnglishGrade(float grade);
    float getEnglishGrade() const;
    
    bool setHistoryGrade(float grade); 
    float getHistoryGrade() const;
    
    float getAverage() const;
};

#endif // STUDENT_H