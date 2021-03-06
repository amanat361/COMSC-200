#ifndef SHAPEMGR_H
#define SHAPEMGR_H

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Spray.h"

const int SIZE = 99;

class ShapeMgr
{
  protected:
    Shape * arrShapes[SIZE] = {nullptr};
    int recordCount = 0;
  public:
    ShapeMgr();
    ~ShapeMgr();
    void populateShapeData();
    void displayAll();
};

#endif // ShapeMgr_H
