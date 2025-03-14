#include <iostream>
#include "Math.h"

int main()
{
    std::cout << "Add(int, int): " << Math::Add(5, 3) << std::endl;
    std::cout << "Add(int, int, int): " << Math::Add(5, 3, 2) << std::endl;
    
    std::cout << "Add(double, double): " << Math::Add(5.5, 3.3) << std::endl;
    std::cout << "Add(double, double, double): " << Math::Add(1.2, 3.4, 5.6) << std::endl;
    
    std::cout << "Mul(int, int): " << Math::Mul(5, 3) << std::endl;
    std::cout << "Mul(int, int, int): " << Math::Mul(5, 3, 2) << std::endl;

    std::cout << "Mul(double, double): " << Math::Mul(5.5, 3.3) << std::endl;
    std::cout << "Mul(double, double, double): " << Math::Mul(1.2, 3.4, 5.6) << std::endl;

    std::cout << "Add(int count, ...): " << Math::Add(4, 1, 2, 3, 4) << std::endl;
    
    char* concatenated = Math::Add("Hello, ", "world!");
    if (concatenated)
    {
        std::cout << "Add(const char*, const char*): " << concatenated << std::endl;
        delete[] concatenated;
    }
    else
    {
        std::cout << "One of the strings is nullptr." << std::endl;
    }
    
    return 0;
}