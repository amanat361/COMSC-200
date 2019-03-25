#ifndef SPRAY_H
#define SPRAY_H

#include "Circle.h"

using namespace std;

class Spray: public Circle
{
  private:
    int density;
  public:
    void setDataTwo(int);
    int getDataTwo();
    void draw();
};

#endif // Square_H
