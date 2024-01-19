#ifndef GEOMETRIES_H
#define GEOMETRIES_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Forward declaration
class PixelBuffer;
class Triangle;

class Point
{
public:
    Point(double x, double y); // x (horizontal), y (vertical)
    std::vector<double> getCoord();
    bool isInTriangle(Triangle tri); // check if Point inside Triangle
private:
    double m_x;
    double m_y;
    std::vector<double> m_coord; // 2D vector representing Points coords (x,y)
};

class Triangle
{
public:
    Triangle(char pix, Point P1, Point P2, Point P3); //char for triangle, coords from 3 vertices
    char getPixel();
    std::vector<Point> getPoints();
    std::vector<double> limitTriangle(); //return x/y min:max from triangle

private:
    char m_pix;
    Point m_P1;
    Point m_P2;
    Point m_P3;
};

#endif

