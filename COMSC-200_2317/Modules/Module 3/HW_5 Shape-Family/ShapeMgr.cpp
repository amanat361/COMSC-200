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
    else if (temp[0] == 'C') arrShapes[recordCount] = new Circle;
    else if (temp[0] == 'S') arrShapes[recordCount] = new Spray;
    else cout << "Shape does not exist" << endl << endl;

    if (temp[0] == 'R' || temp[0] == 'Q' || temp[0] == 'C' || temp[0] == 'S')
    {
      stream >> temp;
      arrShapes[recordCount]->setSerialNumber(stoi(temp));

      stream >> temp;
      arrShapes[recordCount]->setDataOne(stoi(temp));

      stream >> temp;
      arrShapes[recordCount]->setDataTwo(stoi(temp));
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

void ShapeMgr::displayAll()
{
  cout << endl;
  for (int i = 0; i < recordCount; i++)
  {
    arrShapes[i]->draw();
  }
}
