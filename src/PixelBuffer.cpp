#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

PixelBuffer::PixelBuffer(char bg, int w, int h) : m_bgChar(bg), m_width(w), m_heigth(h), m_pixelBuffer(m_heigth,vector<char>(m_width, bg)) {}

void PixelBuffer::clear()
{
    m_pixelBuffer = vector<vector<char>>(m_heigth, vector<char>(m_width, m_bgChar));
}

void PixelBuffer::affiche() const
{
    for(int y = 0; y < m_heigth; ++y)
    {
        for(int x = 0; x < m_width; ++x)
        {
            cout << m_pixelBuffer[y][x];
        }
    }
    cout << endl;
}

vector<int> PixelBuffer::getDimension()
{
    return {m_width, m_heigth};
}

void PixelBuffer::placePix(char pixel, Point p)
{
    int x = round(p.getCoord()[0]);
    int y = round(p.getCoord()[1]);
    if(x<=m_width && y<=m_heigth)
    {
        m_pixelBuffer[y][x] = pixel;
    }
}

void PixelBuffer::drawTriangle(char pix, Triangle tri)
{
    vector<double> limits = tri.limitTriangle();
    int xMin, xMax, yMin, yMax;
    xMin = round(limits[0]);
    xMax = round(limits[1]);
    yMin = round(limits[2]);
    yMax = round(limits[3]);

    for(int y = yMin; y < yMax; ++y)
    {
        for(int x = xMin; x < xMax; ++x)
        {
            Point p(x,y);
            if (p.isInTriangle(tri))
            {
                placePix(pix, p);
            }
        }
    }
}