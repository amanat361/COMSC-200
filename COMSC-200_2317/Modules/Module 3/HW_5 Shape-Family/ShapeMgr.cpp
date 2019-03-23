#include "ShapeMgr.h"

using namespace std;

ShapeMgr::ShapeMgr()
{
  fstream inputFile;
  string fileName = "shaperecords.txt";
  string line, temp;
  inputFile.open(fileName);

  while (getline(inputFile, line))
  {
    stringstream stream(line);
    stream >> temp;

    if (temp[0] == 'R') arrShapes[recordCount] = new Rectangle;
    else if (temp[0] == 'Q') arrShapes[recordCount] = new Square;

    if (temp[0] == 'R' || temp[0] == 'Q')
    {
      stream >> temp;
      arrShapes[recordCount]->setSerialNumber(stoi(temp));
      cout << arrShapes[recordCount]->getSerialNumber() << ", ";

      stream >> temp;
      arrShapes[recordCount]->setDataOne(stoi(temp));
      cout << arrShapes[recordCount]->getDataOne() << ", ";

      stream >> temp;
      arrShapes[recordCount]->setDataTwo(stoi(temp));
      cout << arrShapes[recordCount]->getDataTwo() << endl;
    }

    recordCount++;
  }

  inputFile.close();
}

ShapeMgr::~ShapeMgr()
{
  for (int i = 0; i < SIZE; i++)
  {
    if (arrShapes[i] != nullptr)
    {
      delete[] arrShapes[i];
    }
  }
}

void displayAll()
{}
