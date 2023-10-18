#ifndef PIXELBUFFER_HPP
#define PIXELBUFFER_HPP

#include <iostream>
#include <vector>

class PixelBuffer
{
    public:
        PixelBuffer(char, int, int);
        void affiche() const;
        void placePix(char pix, int x, int y);
    private:
        char m_bgChar;
        int m_width;
        int m_heigth; 
        std::vector<char> m_pixelBuffer;
};
#endif