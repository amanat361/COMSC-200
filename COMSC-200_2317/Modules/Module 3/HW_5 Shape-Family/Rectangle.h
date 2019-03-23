#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

using namespace std;

class Rectangle: public Shape
{
  protected:
    int width;
    int height;
  public:
    virtual void setDataOne(int);
    virtual int getDataOne();
    virtual void setDataTwo(int);
    virtual int getDataTwo();
};

#endif // Rectangle_H
