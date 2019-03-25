#include "Rectangle.h"

void Rectangle::setDataOne(int x)
{
  width = x;
}

int Rectangle::getDataOne()
{
  return width;
}

void Rectangle::setDataTwo(int x)
{
  height = x;
}

int Rectangle::getDataTwo()
{
  return height;
}

void Rectangle::draw()
{
  cout << "-----Rectangle object-----" << endl << endl;
  cout << " Serial number: " << serialNumber << endl;
  cout << " Width: " << width << endl;
  cout << " Height: " << height << endl << endl;
}
