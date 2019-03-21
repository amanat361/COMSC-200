#ifndef SHAPEMGR_H
#define SHAPEMGR_H

#include "Shape.h"

const int SIZE = 99;

using namespace std;

class ShapeMgr
{
private:
  Shape * arrShapes[SIZE] = {nullptr};
  int recordCount = 0;
public:
  ShapeMgr();
  ~ShapeMgr();
  int getRecordCount() const;
  void displayAll();
}

#endif // ShapeMgr_H
