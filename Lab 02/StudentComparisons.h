#ifndef STUDENTCOMPARISONS_H
#define STUDENTCOMPARISONS_H

#include "Student.h"

int compareByName(const Student &s1, const Student &s2);
int compareByMath(const Student &s1, const Student &s2);
int compareByEnglish(const Student &s1, const Student &s2);
int compareByHistory(const Student &s1, const Student &s2);
int compareByAverage(const Student &s1, const Student &s2);

#endif // STUDENTCOMPARISONS_H