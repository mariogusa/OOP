#include "Student.h"

Student::Student() : name(""), mathGrade(0), englishGrade(0), historyGrade(0) {}

Student::Student(const std::string &name, float mathGrade, float englishGrade, float historyGrade)
    : name(name), mathGrade(0), englishGrade(0), historyGrade(0) {
    setMathGrade(mathGrade);
    setEnglishGrade(englishGrade);
    setHistoryGrade(historyGrade);
}

void Student::setName(const std::string &name) {
    this->name = name;
}

std::string Student::getName() const {
    return name;
}

bool Student::setMathGrade(float grade) {
    if (grade < 1.0f || grade > 10.0f)
        return false;
    mathGrade = grade;
    return true;
}

float Student::getMathGrade() const {
    return mathGrade;
}

bool Student::setEnglishGrade(float grade) {
    if (grade < 1.0f || grade > 10.0f)
        return false;
    englishGrade = grade;
    return true;
}

float Student::getEnglishGrade() const {
    return englishGrade;
}

bool Student::setHistoryGrade(float grade) {
    if (grade < 1.0f || grade > 10.0f)
        return false;
    historyGrade = grade;
    return true;
}

float Student::getHistoryGrade() const {
    return historyGrade;
}

float Student::getAverage() const {
    return (mathGrade + englishGrade + historyGrade) / 3.0f;
}