#include <iostream>
#include <vector>
//
#include "PixelBuffer.hpp"

using namespace std;

int main ()
{
    PixelBuffer myBuffer('*', 80, 24);
    myBuffer.placePix('-',1,10);
    myBuffer.affiche();
    return 0;
}