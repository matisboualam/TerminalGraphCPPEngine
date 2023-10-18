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

void PixelBuffer::placePix(char pixel, int x, int y)
{
    m_pixelBuffer[x*m_width + y] = pixel;
}

