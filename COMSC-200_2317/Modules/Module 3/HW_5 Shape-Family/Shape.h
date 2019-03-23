#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Shape
{
  protected:
    int serialNumber = 0;
  public:
    void setSerialNumber(int);
    int getSerialNumber() const;

    virtual void setDataOne(int) = 0;
    virtual int getDataOne() = 0;
    virtual void setDataTwo(int) = 0;
    virtual int getDataTwo() = 0;
};

#endif // Shape_H
