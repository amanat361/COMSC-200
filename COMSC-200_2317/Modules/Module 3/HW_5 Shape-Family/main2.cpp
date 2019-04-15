#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

const int SIZE = 99;

class Shape
{
  protected:
    int serialNumber = 0;
  public:
    virtual void setDataOne(int) = 0;
    virtual void setDataTwo(int) = 0;
    virtual void draw() = 0;

    void setSerialNumber(int x)
    {
      serialNumber = x;
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
    virtual void setDataTwo(int x)
    {
      height = x;
    }
    virtual void draw()
    {
      cout << "Rectangle #" << serialNumber << endl;
      cout << "Width: " << width << " / Height: " << height << endl << endl;
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++)
        {
          cout << "* ";
        }
        cout << endl;
      }
      cout << endl;
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
    void setDataTwo(int x)
    {
      dummy = x;
    }
    void draw()
    {
      cout << "Square #" << serialNumber << endl;
      cout << "Side: " << side << endl << endl;
      for (int i = 0; i < side; i++)
      {
        for (int j = 0; j < side; j++)
        {
          cout << "* ";
        }
        cout << endl;
      }
      cout << endl;
    }
};

class Circle: public Shape
{
  protected:
    int radius;
    int dummy;
    double z;
  public:
    virtual void setDataOne(int x)
    {
      radius = x;
    }
    virtual void setDataTwo(int x)
    {
      dummy = x;
    }

    virtual void draw()
    {
      float console_ratio = 4.0/3.0;
      float circle_radius = radius;
      float a = console_ratio*circle_radius;
      float b = circle_radius;

      for (int y = -circle_radius; y <= circle_radius; y++)
      {
          for (int x = -console_ratio*circle_radius; x <= console_ratio*circle_radius; x++)
          {
              float d = (x/a)*(x/a) + (y/b)*(y/b);
              if (d > 0.90 && d < 1.1)
              {
                  cout << "loading ";
              }
              else
              {
                   cout << " ";
              }
          }
          cout << endl;
      }
    }

    /*
    virtual void draw()
    {
      cout << "Circle #" << serialNumber << endl;
      cout << "Radius: " << radius << endl << endl;
      for (int y = -radius; y < radius + 1; y++)
      {
        for (int x = -radius; x < radius + 1; x++)
        {
          z = sqrt((x*x) + (y*y));
          if (-0.6 <= (radius - z) && (radius - z) <= 0.6) cout << "*";
          else cout << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
    */
};

class Spray: public Circle
{
  private:
    int density;
    int randomValue;
  public:
    void setDataTwo(int x)
    {
      density = x;
    }

    void draw()
    {
      cout << "Spray #" << serialNumber << endl;
      cout << "Radius: " << radius << " / Density: " << density << endl << endl;

      srand(time(NULL));

      for (int y = -radius; y < radius + 1; y++)
      {
        for (int x = -radius; x < radius + 1; x++)
        {
          z = sqrt((x*x) + (y*y));

          if (-0.6 <= (radius - z) && (radius - z) <= 0.6)
          {
            cout << "loading ";
          }

          else if (z < radius)
          {
            randomValue = (rand() % 100); //range is 0 - 99
            if (randomValue < density) cout << "loading ";
            else cout << " ";
          }
          else cout << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
};

class ShapeMgr
{
  private:
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
