#include "ManageTerminal.hpp"

using namespace std;

void draw(vector<char>& pixBuffer)
{
    for(int i = 0; i<pixBuffer.size(); ++i)
    {
        cout << pixBuffer[i];
    }
    cout << " ";
}

vector<char> clear(vector<char>& pixBuffer)
{
    vector<char> null(pixBuffer.size(),' ');
    pixBuffer = null;
    return pixBuffer;
    }