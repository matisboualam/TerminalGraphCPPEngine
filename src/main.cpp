#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "PixelBuffer.hpp"
#include "Geometries.hpp"

using namespace std;


int main ()
{
    int width = WIDTH;
    int height = HEIGHT - 1; //nothing displayable in terminal's last line

    PixelBuffer myBuffer(' ', width, height);
    Point3D O(-0.5,-0.5,1);
    Point3D P(0.5,-0.5,1);
    Point3D Q(0,0.5,1);
    Triangle3D tri('o', O, P, Q);

    double t = 0;
    while(1)
    {
        t -= 0.1;
        myBuffer.clear();        
        myBuffer.putTriangle2D(tri.translate(Point3D(t,t,1)).projection());
        myBuffer.draw();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    return 0;
}
