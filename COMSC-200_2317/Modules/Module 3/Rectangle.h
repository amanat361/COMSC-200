#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Rectangle
{
private:
    int serialNumber;
    double width;
    double height;

public:
    Rectangle(double, double);
    ~Rectangle();
    void setWidth(double);
    void setHeight(double);
    void setSerialNumber(int);
    double getWidth() const;
    double getHeight() const;
    int getSerialNumber() const;
};
