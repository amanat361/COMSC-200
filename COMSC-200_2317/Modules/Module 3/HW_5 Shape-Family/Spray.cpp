#include "Spray.h"

void Spray::setDataTwo(int x)
{
  density = x;
}

int Spray::getDataTwo()
{
  return density;
}

void Spray::draw()
{
  cout << "-----Spray object-----" << endl << endl;
  cout << " Serial number: " << serialNumber << endl;
  cout << " Radius: " << radius << endl;
  cout << " Density: " << density << endl << endl;
}
