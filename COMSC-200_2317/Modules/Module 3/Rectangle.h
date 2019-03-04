#include <iostream> //console input/output
#include <stdlib.h> //random number generation
#include <time.h> //random num generation seed
#include <string> //string data type

#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle
{
private:
    int serialNumber;
    string outputLabel;
    double width;
    double height;

public:
    static int totalRectangles;
    static int totalSquares;
    static int totalVerticals;
    static int totalHorizontals;
    Rectangle(double, double);
    ~Rectangle();
    void setWidth(double);
    void setHeight(double);
    void setSerialNumber(int);
    void setOutputLabel(string);
    double getWidth() const;
    double getHeight() const;
    int getSerialNumber() const;
    string getOutputLabel() const;
};

#endif
