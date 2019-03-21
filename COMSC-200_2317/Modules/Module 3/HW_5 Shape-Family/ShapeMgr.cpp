#include "ShapeMgr.h"

using namespace std;

ShapeMgr::ShapeMgr()
{
  string line;
  int pos, pos2;

  char shapeTypeX;
  int serialNumberX;
  double radiusX;
  double widthX;
  double sideX;

  fstream inputFile;
  string fileName = "shaperecords.txt";
  inputFile.open(fileName);

  while (getline(inputFile, line))
  {
    arrShapes[recordCount] = new Shape;
    recordCount++;

    shapeTypeX = line.substr(0, 1);
    pos = line.find(' ');
    pos2 = line.find(pos, ' ');
    serialNumberX = line.substr(pos, pos2)
    pos = pos2;
    pos2 = line.find(pos, ' ');

    
  }

  inputFile.close();
}
