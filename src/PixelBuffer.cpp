#include "Geometries.hpp"
#include "PixelBuffer.hpp"

using namespace std;

PixelBuffer::PixelBuffer(char bg, int w, int h) : m_bgChar(bg), m_width(w), m_heigth(h)
{
    m_pixelBuffer = vector<char>(m_width*(m_heigth-1), m_bgChar);
}

void PixelBuffer::affiche() const
{
    for(int i = 0; i<m_pixelBuffer.size(); ++i)
    {
        cout << m_pixelBuffer[i];
    }
    cout << endl;
}

void PixelBuffer::placePix(char pixel, Point p)
{
    int x = round(p.getCoord()[0]);
    int y = round(p.getCoord()[1]);
    if(x<=m_width && y<=m_heigth)
    {
        m_pixelBuffer[x + y*m_width] = pixel;
    }
}

void PixelBuffer::drawTriangle(Triangle tri)
{
    vector<double> limits = tri.limitTriangle();
    // for (int i = 0; i<limits.size(); i++)
    // {
    //     cout << limits[i] << " ";
    // }
    // cout << endl;

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
                placePix(' ',p);
            }
        }
    }
}