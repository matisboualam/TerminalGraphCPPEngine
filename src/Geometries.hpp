#ifndef GEOMETRIES_H
#define GEOMETRIES_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


// Forward declaration
class PixelBuffer;
class Point2D;
class Triangle2D;
class Point3D;
class Triangle3D;
class Camera;

class Point2D
{
public:
    Point2D(double x, double y); // x (horizontal), y (vertical) normalized (between -1:1)
    bool isInTriangle2D(Triangle2D tri); // check if Point2D inside Triangle2D
    void toScreen(); // rescale coords to buffer dimension
    std::vector<double> getCoord();

    Point2D operator*(const double c) const;
    Point2D operator/(const double c) const;
    Point2D operator+(const Point2D P) const;

private:
    double m_x;
    double m_y;
    std::vector<double> m_coord; // 2D vector representing Point2Ds coords (x,y)
};

class Point3D
{
public:
    Point3D(double x, double y, double z); // x (horizontal), y (vertical) normalized (between -1:1)
    std::vector<double> getCoord();
    Point2D projection(double focalLength); // 3D to 2D point
    Point3D rotationX(double pitch);
    Point3D rotationY(double yaw);

    Point3D operator*(const double c) const;
    Point3D operator/(const double c) const;
    Point3D operator+(const Point3D P) const;
    
private:
    double m_x;
    double m_y;
    double m_z;
    std::vector<double> m_coord; // 2D vector representing Point2Ds coords (x,y)
};

class Triangle2D
{
public:
    Triangle2D(char pix, Point2D P1, Point2D P2, Point2D P3); //char for Triangle2D, coords from 3 vertices
    char getPixel();
    std::vector<Point2D> getPoint2Ds();
    std::vector<double> limitTriangle2D(); //return x/y min:max from Triangle2D

private:
    char m_pix;
    Point2D m_P1;
    Point2D m_P2;
    Point2D m_P3;
};

class Triangle3D
{
public:
    Triangle3D(char pix, Point3D P1, Point3D P2, Point3D P3); //char for Triangle3D, coords from 3 vertices
    Triangle2D projection(double focalLength);
    Triangle3D translate(Point3D P);
    Triangle3D rotationX(double pitch);
    Triangle3D rotationY(double yaw);
    
private:
    char m_pix;
    Point3D m_P1;
    Point3D m_P2;
    Point3D m_P3;
};

#endif

