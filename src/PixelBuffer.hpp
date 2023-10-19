#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Forward declaration
class Point;
class Triangle;

class PixelBuffer
{
public:
    PixelBuffer(char, int, int);
    void affiche() const;
    void placePix(char pix, Point p);
    std::vector<int> getDimension();
    void drawTriangle(char pix, Triangle tri);
    void clear();
private:
    char m_bgChar;
    int m_width;
    int m_heigth;
    std::vector<std::vector<char>> m_pixelBuffer;
};

#endif
