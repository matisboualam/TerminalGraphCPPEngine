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
    Point(double x, double y);
    std::vector<double> getCoord();
    bool isInTriangle(Triangle tri);
private:
    double m_x;
    double m_y;
    std::vector<double> m_coord;
};

class Triangle
{
public:
    Triangle(Point P1, Point P2, Point P3);
    std::vector<Point> getPoints();
    std::vector<double> limitTriangle();

private:
    Point m_P1;
    Point m_P2;
    Point m_P3;
};

#endif

