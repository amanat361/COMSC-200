#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <time.h>

using namespace std;

#include "Rectangle.h"

const int SIZE = 21;

void display(Rectangle *[]);

int main()
{
    srand(time(NULL));
    Rectangle * arrRect[SIZE];
    //Rectangle::totalRectangles = 0;

    for (int i=0; i < SIZE; i++)
    {
         arrRect[i] = new Rectangle(rand()%10, rand()%10);
         Rectangle::totalRectangles++;
    }
    display(arrRect);

}

void display(Rectangle * arr[])
{

    for (int i=0; i < SIZE; i++)
    {
         cout << "R";
         if ((arr[i]->getSerialNumber()) < 10) cout << "000";
         else if ((arr[i]->getSerialNumber()) < 100) cout << "00";
         else if ((arr[i]->getSerialNumber()) < 1000) cout << "0";
         cout << arr[i]->getSerialNumber() << endl;  /// Display the serial number of the Rectangle object
    }

}
