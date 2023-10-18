#include <iostream>
#include <vector>
#include <cmath>
//
#include "PixelBuffer.hpp"
#include "Geometries.hpp"

using namespace std;

int main ()
{
    PixelBuffer myBuffer('*', 80, 24);
    Point P1(10, 3.14), P2(46, 0), P3(76, 22);
    Triangle tri(P1, P2, P3);
    myBuffer.drawTriangle(tri);
    myBuffer.affiche();
    return 0;
}