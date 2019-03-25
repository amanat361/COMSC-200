#include "Square.h"

void Square::setDataOne(int x)
{
  side = x;
}

int Square::getDataOne()
{
  return side;
}

void Square::setDataTwo(int x)
{
  dummy = x;
}

int Square::getDataTwo()
{
  return dummy;
}

void Square::draw()
{
  cout << "-----Square object-----" << endl << endl;
  cout << " Serial number: " << serialNumber << endl;
  cout << " Side: " << side << endl << endl;
}
