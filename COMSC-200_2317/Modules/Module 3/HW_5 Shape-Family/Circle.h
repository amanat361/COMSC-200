#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

using namespace std;

class Circle: public Shape
{
  protected:
    int radius;
    int dummy;
  public:
    virtual void setDataOne(int);
    virtual int getDataOne();
    virtual void setDataTwo(int);
    virtual int getDataTwo();
};

#endif // Circle_H
