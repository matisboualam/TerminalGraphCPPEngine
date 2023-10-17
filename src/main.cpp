#include <iostream>
#include <vector>
//
#include "ManageTerminal.hpp"
#include "LibMath.hpp"


using namespace std;

int main ()
{
    int width(80), height(24);
    vector<char> pixelBuffer(width*height, '*');
    draw(pixelBuffer);
    clear(pixelBuffer);
    draw(pixelBuffer);
    return 0;
}