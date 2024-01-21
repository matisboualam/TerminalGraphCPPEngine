#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H
#define WIDTH 90
#define HEIGHT 30
#define SCREEN_RATIO 0.7

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Geometries.hpp"


// Forward declaration
class PixelBuffer;
class Point2D;
class Triangle2D;
class Point3D;
class Triangle3D;
class Camera;

class PixelBuffer
{
public:
    PixelBuffer(char, int, int); //char for background, width, height
    void draw() const; //display Buffer
    bool isInBuffer(Point2D p); // check if Point2D outside Buffer dimension
    void putPixel(char pix, Point2D p); //place a pixel in the Buffer regarding the coord from Point2D
    void putTriangle2D(Triangle2D tri);
    void putMesh(std::vector<Triangle3D> mesh, Camera cam); //place a list of Triangle3D in the Buffer
    void clear(); //clears Buffer
private:
    char m_bgChar;
    int m_width;
    int m_height;
    std::vector<std::vector<char>> m_pixelBuffer;
};


class Camera
{
public:
    Camera(Point3D, double, double);
    Point3D getPos();
    double getPitch();
    double getYaw();
    double getFocalLength();
private:
    Point3D m_position;
    double m_pitch;
    double m_yaw;
    double m_focalLength;
};

#endif
