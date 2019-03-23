#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

using namespace std;

class Square: public Rectangle
{
  private:
    int side;
    int dummy;
  public:
    void setDataOne(int);
    int getDataOne();
    void setDataTwo(int);
    int getDataTwo();
};

#endif // Square_H
