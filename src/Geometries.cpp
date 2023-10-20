#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

Point::Point (double x, double y) : m_x(x), m_y(y)
{
    m_coord.push_back(m_x);
    m_coord.push_back(m_y);
}

vector<double> Point::getCoord()
{
    return m_coord;
}



bool Point::isInTriangle(Triangle tri)
{
    Point P1 =  tri.getPoints()[0];
    Point P2 =  tri.getPoints()[1];
    Point P3 =  tri.getPoints()[2];
    int side1 = (P2.getCoord()[0] - P1.getCoord()[0]) * (m_y - P1.getCoord()[1]) - (P2.getCoord()[1] - P1.getCoord()[1]) * (m_x - P1.getCoord()[0]);
    int side2 = (P3.getCoord()[0] - P2.getCoord()[0]) * (m_y - P2.getCoord()[1]) - (P3.getCoord()[1] - P2.getCoord()[1]) * (m_x - P2.getCoord()[0]);
    int side3 = (P1.getCoord()[0] - P3.getCoord()[0]) * (m_y - P3.getCoord()[1]) - (P1.getCoord()[1] - P3.getCoord()[1]) * (m_x - P3.getCoord()[0]);
    
    return ((side1 >= 0 && side2 >= 0 && side3 >= 0) || (-side1 >= 0 && -side2 >= 0 && -side3 >= 0));
}


Triangle::Triangle (Point P1, Point P2, Point P3) : m_P1(P1), m_P2(P2), m_P3(P3)
{}

vector<Point> Triangle::getPoints()
{
    vector<Point> listPoints;
    listPoints.push_back(m_P1);
    listPoints.push_back(m_P2);
    listPoints.push_back(m_P3);
    return listPoints;
}

vector<double> Triangle::limitTriangle()
{    
    double xMin, xMax, yMin, yMax;
    vector<double> Xs = {m_P1.getCoord()[0], m_P2.getCoord()[0], m_P3.getCoord()[0]};
    sort(Xs.begin(), Xs.end());
    xMin = Xs[0];
    xMax = Xs[2]+1;

    vector<double> Ys = {m_P1.getCoord()[1], m_P2.getCoord()[1], m_P3.getCoord()[1]};
    sort(Ys.begin(), Ys.end());
    yMin = Ys[0];
    yMax = Ys[2]+1;

    vector<double> limits = {xMin, xMax, yMin, yMax};
    return limits;
}