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
    Point3D camPos = Point3D(0,0,3);

    Camera cam(camPos, 0, 0);

    Point3D O(-0.5,-0.9,0);
    Point3D P(0.5,-0.9,0);
    Point3D Q(0,0,0);
    Triangle3D tri1('.', O, P, Q);

    Point3D R(0,-0.9,-0.5);
    Point3D S(0,-0.9,0.5);
    Point3D T(0,0,0);
    Triangle3D tri2('.', R, S, T);

    vector<Triangle3D> mesh({tri1,tri2});

    double t = 0;
    while(1)
    {
        t += 0.1;
        myBuffer.clear();   
        myBuffer.putMesh(mesh, cam);
        myBuffer.draw();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}
