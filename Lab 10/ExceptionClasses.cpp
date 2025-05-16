#include <iostream>
#include <exception>
using namespace std;

class OutOfRangeException : public exception {
    const char* what() const throw() override {
        return "Index out of range!";
    }
};

class FullArrayException : public exception {
    const char* what() const throw() override {
        return "Array is full!";
    }
};