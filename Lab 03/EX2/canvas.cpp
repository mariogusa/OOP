#include "Canvas.h"
#include <cmath>
#include <algorithm>

Canvas::Canvas(int width, int height) : width(width), height(height)
{
    matrix.resize(height, std::vector<char>(width, ' '));
}

void Canvas::Clear()
{
    for (int i = 0; i < height; ++i)
    {
        std::fill(matrix[i].begin(), matrix[i].end(), ' ');
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        matrix[y][x] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::PlotCirclePoints(int cx, int cy, int x, int y, char ch)
{
    SetPoint(cx + x, cy + y, ch);
    SetPoint(cx - x, cy + y, ch);
    SetPoint(cx + x, cy - y, ch);
    SetPoint(cx - x, cy - y, ch);
    SetPoint(cx + y, cy + x, ch);
    SetPoint(cx - y, cy + x, ch);
    SetPoint(cx + y, cy - x, ch);
    SetPoint(cx - y, cy - x, ch);
}

void Canvas::DrawCircle(int cx, int cy, int ray, char ch)
{
    int x = 0;
    int y = ray;
    int d = 3 - 2 * ray;
    PlotCirclePoints(cx, cy, x, y, ch);
    while (y >= x)
    {
        ++x;
        if (d > 0)
        {
            --y;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        PlotCirclePoints(cx, cy, x, y, ch);
    }
}

void Canvas::FillCircle(int cx, int cy, int ray, char ch)
{
    for (int y = -ray; y <= ray; ++y)
    {
        for (int x = -ray; x <= ray; ++x)
        {
            if (x * x + y * y <= ray * ray)
            {
                SetPoint(cx + x, cy + y, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; ++x)
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }

    for (int y = top; y <= bottom; ++y)
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; ++y)
    {
        for (int x = left; x <= right; ++x)
        {
            SetPoint(x, y, ch);
        }
    }
}