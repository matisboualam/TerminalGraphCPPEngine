#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

PixelBuffer::PixelBuffer(char bg, int w, int h) : m_bgChar(bg), m_width(w), m_height(h), m_pixelBuffer(m_height,vector<char>(m_width, bg)) {}

void PixelBuffer::clear()
{
    m_pixelBuffer = vector<vector<char>>(m_height, vector<char>(m_width, m_bgChar));
}

void PixelBuffer::draw() const
{
    for(int y = 0; y < m_height; ++y)
    {
        for(int x = 0; x < m_width; ++x)
        {
            cout << m_pixelBuffer[y][x];
        }
    }
    cout << endl;
}

bool PixelBuffer::isInBuffer(Point2D p)
{
    int x = p.getCoord()[0];
    int y = p.getCoord()[1];
    return (x >= 0 && x<m_width && y >= 0 && y < m_height);
}

void PixelBuffer::putPixel(char pixel, Point2D p)
{
    int x = round(p.getCoord()[0]);
    int y = round(p.getCoord()[1]);
    
    if (isInBuffer(p))
    {
        m_pixelBuffer[y][x] = pixel;
    }
}

void PixelBuffer::putTriangle2D(Triangle2D tri)
{
    vector<double> limits = tri.limitTriangle2D();
    int xMin, xMax, yMin, yMax;
    xMin = round(limits[0]);
    xMax = round(limits[1]);
    yMin = round(limits[2]);
    yMax = round(limits[3]);

    for(int y = yMin; y < yMax; ++y)
    {
        for(int x = xMin; x < xMax; ++x)
        {
            Point2D p(x,y);
            if (p.isInTriangle2D(tri))
            {
                putPixel(tri.getPixel(), p);
            }
        }
    }
}