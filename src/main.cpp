#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
//
#include "PixelBuffer.hpp"
#include "Geometries.hpp"

using namespace std;

// PARAM SCREEN
#define WIDTH 80
#define HEIGHT 24


int main ()
{
    int width = WIDTH;
    int height = HEIGHT - 1; //nothing displayable in terminal's last line

    PixelBuffer myBuffer(' ', width, height);
    Point O(4,5);
    Point P(34,15);
    Point Q(75,2);
    
    
    int i = 0;
    int z = 0;
    while(1)
    {
        // i--;
        z++;
        Point O(75+i,2+z);
        Point P(WIDTH/2+i,HEIGHT/2+z);
        Point Q(75+i,20+z); 
        Triangle tri('/', O, P, Q);

        myBuffer.clear();        
        // myBuffer.putPixel('*', O);
        myBuffer.putTriangle(tri);
        myBuffer.draw();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    return 0;
}
