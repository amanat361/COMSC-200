#include "ShapeMgr.h"

using namespace std;

//constructor
ShapeMgr::ShapeMgr()
{
  populateShapeData();
}

//destructor
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

//create shapes
void ShapeMgr::populateShapeData()
{
  //input file data
  fstream inputFile;
  string fileName = "shaperecords.txt";
  string line, temp;
  char shapeType;
  inputFile.open(fileName);

  //if shape
  bool validShape;

  while (getline(inputFile, line))
  {
    //turn line into stringstream to separate each piece of data
    stringstream stream(line);

    //take first piece (type of shape) as temp
    stream >> temp;
    shapeType = temp[0];

    //create shape
    validShape = true;
    if (shapeType == 'R') arrShapes[recordCount] = new Rectangle;
    else if (shapeType == 'Q') arrShapes[recordCount] = new Square;
    else if (shapeType == 'C') arrShapes[recordCount] = new Circle;
    else if (shapeType == 'S') arrShapes[recordCount] = new Spray;
    else
    {
      cout << "Shape does not exist" << endl << endl;
      validShape = false;
    }

    //If shhape is valid, fill in setSerialNumber, dateOne, and dataTwo
    if (validShape)
    {
      stream >> temp;
      arrShapes[recordCount]->setSerialNumber(stoi(temp));

      stream >> temp;
      arrShapes[recordCount]->setDataOne(stoi(temp));

      stream >> temp;
      arrShapes[recordCount]->setDataTwo(stoi(temp));
    }

    //increment count of shapes
    recordCount++;
  }

  //close file
  inputFile.close();
}

//display shapes
void ShapeMgr::displayAll()
{
  cout << endl;
  for (int i = 0; i < recordCount; i++)
  {
    //because of polymorphism, each shape has a different draw() function
    arrShapes[i]->draw();
  }
}
