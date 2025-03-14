#include "Canvas.h"
#include <iostream>

int main()
{
    Canvas canvas(50, 20);

    canvas.DrawCircle(25, 10, 8, '*');

    canvas.FillCircle(10, 5, 4, '+');

    canvas.DrawRect(30, 2, 45, 8, '#');

    canvas.FillRect(2, 12, 20, 18, '@');

    canvas.DrawLine(0, 0, 49, 19, '/');

    canvas.SetPoint(5, 5, 'X');

    std::cout << "Canvas with shapes:" << std::endl;
    canvas.Print();

    canvas.Clear();

    std::cout << "\nCleared Canvas:" << std::endl;
    canvas.Print();

    return 0;
}
