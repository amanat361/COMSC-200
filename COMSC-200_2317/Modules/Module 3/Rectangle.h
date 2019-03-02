#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

class Rectangle
{
private:
    int serialNumber;
    double width;
    double height;

public:
    static int totalRectangles;
    Rectangle(double, double);
    ~Rectangle();
    void printTotalRectangles();
    void setWidth(double);
    void setHeight(double);
    void setSerialNumber(int);
    double getWidth() const;
    double getHeight() const;
    int getSerialNumber() const;
};
