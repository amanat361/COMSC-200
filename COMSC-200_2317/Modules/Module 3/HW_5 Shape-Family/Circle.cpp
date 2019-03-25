#include "Circle.h"

void Circle::setDataOne(int x)
{
  radius = x;
}

int Circle::getDataOne()
{
  return radius;
}

void Circle::setDataTwo(int x)
{
  dummy = x;
}

int Circle::getDataTwo()
{
  return dummy;
}

void Circle::draw()
{
  cout << "-----Circle object-----" << endl << endl;
  cout << " Serial number: " << serialNumber << endl;
  cout << " Radius: " << radius << endl << endl;
}
