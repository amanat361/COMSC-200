  #include "Rectangle.h"

    int Rectangle::totalRectangles = 0;

    Rectangle::Rectangle(double w, double h)
    {
        width= w;
        height = h;
        serialNumber = totalRectangles;
    }
    Rectangle::~Rectangle()
    {

    }

    void Rectangle::printTotalRectangles()
    {
        cout << endl << "Total Rectangles: " << totalRectangles << endl;
    }

    void Rectangle::setWidth(double w)
    {
        width = w;
    }

    void Rectangle::setHeight(double h)
    {
        height = h;
    }
    double Rectangle::getWidth() const
    {
        return width;
    }

    double Rectangle::getHeight() const
    {
        return height;
    }

    void Rectangle::setSerialNumber(int s)
    {
        serialNumber = s;
    }
    int Rectangle::getSerialNumber() const
    {
        return serialNumber;
    }
