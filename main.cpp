#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <ncurses.h>

#include "src/PixelBuffer.hpp"
#include "src/Geometries.hpp"

using namespace std;

void inputs(int ch, Camera& cam, double dt)
{
    // Input is available
    switch (ch) 
    {
        case KEY_UP:
            if(cam.getPitch()<1.57)
            {
                cam.setPitch(+0.01*dt);
            }
            break;
        case KEY_DOWN:
            if(cam.getPitch()>-1.57)
            {
                cam.setPitch(-0.01*dt);
            }
            break;
        case KEY_LEFT:
            cam.setYaw(+0.01*dt);
            break;
        case KEY_RIGHT:
            cam.setYaw(-0.01*dt);
            break;
        case 'z':
            cam.setPos(cam.getForwardDirection()*-0.01*dt);
            break;
        case 's':
            cam.setPos(cam.getForwardDirection()*0.01*dt);
            break;
        case 'q':
            cam.setPos(cam.getRightDirection()*0.01*dt);
            break;
        case 'd':
            cam.setPos(cam.getRightDirection()*-0.01*dt);
            break;
    }
};

int main ()
{
    int width = WIDTH ;
    int height = HEIGHT -1; //nothing displayable in terminal's last line

//buffer init
    PixelBuffer myBuffer(' ', width, height);

//cam init
    Point3D camPos = Point3D(0,0,3);
    Camera cam(camPos, 0, 0);

// keyboard interaction
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    int ch;

    Point3D O(0,0,0);
    Point3D P(1,0,0.5);
    Point3D Q(0,1,0);
    Triangle3D tri1('@', O, P, Q);

    Point3D R(1,1,0);
    Point3D S(1,0,-0.5);
    Point3D T(0,1,0);
    Triangle3D tri2('@', R, S, T);

    vector<Triangle3D> mesh({tri1, tri2});

    chrono::high_resolution_clock::time_point last = chrono::system_clock::now();;

    while((ch = getch()) != 'x')
    {
        chrono::high_resolution_clock::time_point current = chrono::system_clock::now();
        chrono::duration<double> dt = chrono::duration_cast<chrono::duration<double>>(current - last);
        last = current;

        myBuffer.clear();   
        if (ch != ERR) 
        {
            inputs(ch, cam, dt.count()*100);
        }
        myBuffer.putMesh(mesh, cam);
        myBuffer.displayCamParam(cam);
        myBuffer.draw();
        // this_thread::sleep_for(chrono::milliseconds(10));
    }
    endwin();
    return 0;
}
