#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H
#define WIDTH 80
#define HEIGHT 24
#define SCREEN_RATIO 0.7

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Forward declaration
class Point2D;
class Triangle2D;

class PixelBuffer
{
public:
    PixelBuffer(char, int, int); //char for background, width, height
    void draw() const; //display Buffer
    bool isInBuffer(Point2D p); // check if Point2D outside Buffer dimension
    void putPixel(char pix, Point2D p); //place a pixel in the Buffer regarding the coord from Point2D
    void putTriangle2D(Triangle2D tri);
    void clear(); //clears Buffer
private:
    char m_bgChar;
    int m_width;
    int m_height;
    std::vector<std::vector<char>> m_pixelBuffer;
};

#endif
