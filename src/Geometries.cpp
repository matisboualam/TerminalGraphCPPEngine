#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

///////////Point2D///////////

Point2D::Point2D (double x, double y) : m_x(x), m_y(y)
{
    m_coord.push_back(m_x);
    m_coord.push_back(m_y);
}

void Point2D::toScreen()
{
    m_coord[0] = (SCREEN_RATIO * m_x + 1) * (WIDTH / 2);
    m_coord[1] = (-m_y * SCREEN_RATIO + 1) * (HEIGHT / 2);
}

vector<double> Point2D::getCoord()
{
    return m_coord;
}

bool Point2D::isInTriangle2D(Triangle2D tri)
{
    Point2D P1 =  tri.getPoint2Ds()[0];
    Point2D P2 =  tri.getPoint2Ds()[1];
    Point2D P3 =  tri.getPoint2Ds()[2];
    int side1 = (P2.getCoord()[0] - P1.getCoord()[0]) * (m_y - P1.getCoord()[1]) - (P2.getCoord()[1] - P1.getCoord()[1]) * (m_x - P1.getCoord()[0]);
    int side2 = (P3.getCoord()[0] - P2.getCoord()[0]) * (m_y - P2.getCoord()[1]) - (P3.getCoord()[1] - P2.getCoord()[1]) * (m_x - P2.getCoord()[0]);
    int side3 = (P1.getCoord()[0] - P3.getCoord()[0]) * (m_y - P3.getCoord()[1]) - (P1.getCoord()[1] - P3.getCoord()[1]) * (m_x - P3.getCoord()[0]);
    
    return ((side1 >= 0 && side2 >= 0 && side3 >= 0) || (-side1 >= 0 && -side2 >= 0 && -side3 >= 0));
}

Point2D Point2D::operator*(const double c) const
{
    return Point2D(m_x * c, m_y * c);
}

Point2D Point2D::operator/(const double c) const
{
    return Point2D(m_x / c, m_y / c);
}

Point2D Point2D::operator+(const Point2D P) const
{
    return Point2D(m_x + P.m_x, m_y + P.m_y);
}

///////////Point3D///////////

Point3D::Point3D (double x, double y, double z) : m_x(x), m_y(y), m_z(z) 
{}

Point2D Point3D::projection()
{
    return Point2D(m_x, m_y) / m_z;
}

Point3D Point3D::operator*(const double c) const
{
    return Point3D(m_x * c, m_y * c, m_z * c);
}

Point3D Point3D::operator/(const double c) const
{
    return Point3D(m_x / c, m_y / c, m_z / c);
}

Point3D Point3D::operator+(const Point3D P) const
{
    return Point3D(m_x + P.m_x, m_y + P.m_y, m_z + P.m_z);
}

///////////Triangle2D///////////

Triangle2D::Triangle2D (char pix, Point2D P1, Point2D P2, Point2D P3) : m_pix(pix), m_P1(P1), m_P2(P2), m_P3(P3)
{
    m_P1.toScreen();
    m_P2.toScreen();
    m_P3.toScreen();
}

char Triangle2D::getPixel()
{
    return m_pix;
}
vector<Point2D> Triangle2D::getPoint2Ds()
{
    vector<Point2D> listPoint2Ds;
    listPoint2Ds.push_back(m_P1);
    listPoint2Ds.push_back(m_P2);
    listPoint2Ds.push_back(m_P3);
    return listPoint2Ds;
}

vector<double> Triangle2D::limitTriangle2D()
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

///////////Triangle3D///////////

Triangle3D::Triangle3D (char pix, Point3D P1, Point3D P2, Point3D P3) : m_pix(pix), m_P1(P1), m_P2(P2), m_P3(P3)
{
}

Triangle2D Triangle3D::projection()
{
    return Triangle2D(m_pix, m_P1.projection(), m_P2.projection(), m_P3.projection());
}

Triangle3D Triangle3D::translate(Point3D P)
{
    return Triangle3D(m_pix, m_P1 + P, m_P2 + P, m_P3 + P);
}