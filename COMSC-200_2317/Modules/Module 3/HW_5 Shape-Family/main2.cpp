#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int SIZE = 99;

class Shape
{
  protected:
    int serialNumber = 0;
  public:
    virtual void setDataOne(int) = 0;
    virtual int getDataOne() = 0;
    virtual void setDataTwo(int) = 0;
    virtual int getDataTwo() = 0;
    virtual void draw() = 0;

    void setSerialNumber(int x)
    {
      serialNumber = x;
    }
    int getSerialNumber() const
    {
      return serialNumber;
    }
};

class Rectangle: public Shape
{
  protected:
    int width;
    int height;
  public:
    virtual void setDataOne(int x)
    {
      width = x;
    }
    virtual int getDataOne()
    {
      return width;
    }
    virtual void setDataTwo(int x)
    {
      height = x;
    }
    virtual int getDataTwo()
    {
      return height;
    }
    virtual void draw()
    {
      cout << "-----Rectangle object-----" << endl << endl;
      cout << " Serial number: " << serialNumber << endl;
      cout << " Width: " << width << endl;
      cout << " Height: " << height << endl << endl;
    }
};

class Square: public Rectangle
{
  private:
    int side;
    int dummy;
  public:
    void setDataOne(int x)
    {
      side = x;
    }
    int getDataOne()
    {
      return side;
    }
    void setDataTwo(int x)
    {
      dummy = x;
    }
    int getDataTwo()
    {
      return dummy;
    }
    void draw()
    {
      cout << "-----Square object-----" << endl << endl;
      cout << " Serial number: " << serialNumber << endl;
      cout << " Side: " << side << endl << endl;
    }
};

class Circle: public Shape
{
  protected:
    int radius;
    int dummy;
  public:
    virtual void setDataOne(int x)
    {
      radius = x;
    }
    virtual int getDataOne()
    {
      return radius;
    }
    virtual void setDataTwo(int x)
    {
      dummy = x;
    }
    virtual int getDataTwo()
    {
      return dummy;
    }
    virtual void draw()
    {
      cout << "-----Circle object-----" << endl << endl;
      cout << " Serial number: " << serialNumber << endl;
      cout << " Radius: " << radius << endl << endl;
    }
};

class Spray: public Circle
{
  private:
    int density;
  public:
    void setDataTwo(int x)
    {
      density = x;
    }
    int getDataTwo()
    {
      return density;
    }
    void draw()
    {
      cout << "-----Spray object-----" << endl << endl;
      cout << " Serial number: " << serialNumber << endl;
      cout << " Radius: " << radius << endl;
      cout << " Density: " << density << endl << endl;
    }
};

class ShapeMgr
{
  protected:
    Shape * arrShapes[SIZE] = {nullptr};
    int recordCount = 0;
  public:
    //constructor
    ShapeMgr()
    {
      populateShapeData();
    }
    //destructor
    ~ShapeMgr()
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
    void populateShapeData()
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
    void displayAll()
    {
      cout << endl;
      for (int i = 0; i < recordCount; i++)
      {
        //because of polymorphism, each shape has a different draw() function
        arrShapes[i]->draw();
      }
    }
};

int main()
{
  ShapeMgr ms;
  ms.displayAll();
  return 0;
}
