#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

#include "Rectangle.h"

const int SIZE = 21;

void display(Rectangle *[]);

int main()
{
    Rectangle * arrRect[SIZE];

    for (int i=0; i < SIZE; i++)
    {
         arrRect[i] = new Rectangle(2.0, 4.0);
         arrRect[i]->setSerialNumber(1000 + i);
    }
    display(arrRect);

}

void display(Rectangle * arr[])
{

    for (int i=0; i < SIZE; i++)
    {
         cout <<  arr[i]->getSerialNumber() << endl;  /// Display the serial number of the Rectangle object
    }

}
