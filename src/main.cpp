#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
//
#include "PixelBuffer.hpp"
#include "Geometries.hpp"

using namespace std;

int main ()
{
    int width = 90;
    int height = 30;
    PixelBuffer myBuffer(' ', width, height);
    Point P1(10, 5), P2(5, 10), P3(15, 10);
    Triangle tri1(P1, P2, P3);
    Point Q1(10, 20), Q2(5, 25), Q3(15, 25);
    Triangle tri2(Q1, Q2, Q3);
    int i = 0;
    while(1)
    {
        i++;
        myBuffer.clear();
        P1 = Point(P1.getCoord()[0]+i, P1.getCoord()[1]); 
        P2 = Point(P2.getCoord()[0]+i/2, P2.getCoord()[1]); 
        P3 = Point(P3.getCoord()[0]+i, P3.getCoord()[1]); 
        tri1 = Triangle(P1, P2, P3);

        Q1 = Point(Q1.getCoord()[0]+i, Q1.getCoord()[1]); 
        Q2 = Point(Q2.getCoord()[0]+i, Q2.getCoord()[1]+i); 
        Q3 = Point(Q3.getCoord()[0]+i/2, Q3.getCoord()[1]); 
        tri2 = Triangle(Q1, Q2, Q3);

        myBuffer.drawTriangle('1', tri1);
        myBuffer.drawTriangle('2', tri2);
        myBuffer.affiche();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}