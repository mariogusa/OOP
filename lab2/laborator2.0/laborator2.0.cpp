#include "Student.h"
#include <iostream>

int main()
{
    Student student1, student2;

    student1.SetName("Mario");
    student1.SetGradeMath(8.0);
    student1.SetGradeEnglish(9.0);
    student1.SetGradeHistory(6.5);

    student2.SetName("Stefan");
    student2.SetGradeMath(7.0);
    student2.SetGradeEnglish(9.0);
    student2.SetGradeHistory(8.0);

    std::cout << "Comparing by name: " << CompareByName(student1, student2) << std::endl;
    std::cout << "Comparing by grades: " << CompareByMathGrade(student1, student2) << std::endl;
    std::cout << "Comparing by grades: " << CompareByEnglishGrade(student1, student2) << std::endl;
    std::cout << "Comparing by grades: " << CompareByHistoryGrade(student1, student2) << std::endl;
    std::cout << "Comparing by average: " << CompareByAverage(student1, student2) << std::endl;

    return 0;
}
