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
    PixelBuffer(char, int, int); //char for background, width, height
    void draw() const; //display Buffer
    bool isInBuffer(Point p); // check if Point outside Buffer dimension
    void putPixel(char pix, Point p); //place a pixel in the Buffer regarding the coord from Point
    void putTriangle(Triangle tri);
    void clear(); //clears Buffer
private:
    char m_bgChar;
    int m_width;
    int m_height;
    std::vector<std::vector<char>> m_pixelBuffer;
};

#endif
