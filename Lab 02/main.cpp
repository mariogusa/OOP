#include <iostream>
#include "NumberList.h"
#include "Student.h"
#include "StudentComparisons.h"

int main() {
    NumberList list;
    list.Init();
    list.Add(7);
    list.Add(4);
    list.Add(8);
    list.Add(3);
    list.Add(9);

    std::cout << "Original list: ";
    list.Print();

    list.Sort();
    std::cout << "Sorted list: ";
    list.Print();


    Student s1("Andrei", 9.0f, 8.5f, 7.5f);
    Student s2("Radu", 8.0f, 9.0f, 8.0f);

    std::cout << "Student 1: " << s1.getName()
              << " | Math: " << s1.getMathGrade()
              << " | English: " << s1.getEnglishGrade()
              << " | History: " << s1.getHistoryGrade()
              << " | Average: " << s1.getAverage() << std::endl;

    std::cout << "Student 2: " << s2.getName()
              << " | Math: " << s2.getMathGrade()
              << " | English: " << s2.getEnglishGrade()
              << " | History: " << s2.getHistoryGrade()
              << " | Average: " << s2.getAverage() << std::endl;

    std::cout << "Comparison by Name: " << compareByName(s1, s2) << std::endl;
    std::cout << "Comparison by Math: " << compareByMath(s1, s2) << std::endl;
    std::cout << "Comparison by English: " << compareByEnglish(s1, s2) << std::endl;
    std::cout << "Comparison by History: " << compareByHistory(s1, s2) << std::endl;
    std::cout << "Comparison by Average: " << compareByAverage(s1, s2) << std::endl;

    return 0;
}