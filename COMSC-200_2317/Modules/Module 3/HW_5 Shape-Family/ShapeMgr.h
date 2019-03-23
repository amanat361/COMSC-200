#ifndef SHAPEMGR_H
#define SHAPEMGR_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"

const int SIZE = 99;

class ShapeMgr
{
  private:
    char shapeType;
  protected:
    Shape * arrShapes[SIZE] = {nullptr};
    int recordCount = 0;
  public:
    ShapeMgr();
    ~ShapeMgr();
    void displayAll();
};

#endif // ShapeMgr_H
