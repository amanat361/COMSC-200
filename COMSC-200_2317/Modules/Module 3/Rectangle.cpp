  #include "Rectangle.h" //link files

    //Static integer values for counters of rectangles and rectangles of different types
    int Rectangle::totalRectangles = 0;
    int Rectangle::totalSquares = 0;
    int Rectangle::totalVerticals = 0;
    int Rectangle::totalHorizontals = 0;

    //Constructor
    Rectangle::Rectangle(double w, double h)
    {
        width= w;
        height = h;
        serialNumber = totalRectangles;
    }

    //Deconstructor
    Rectangle::~Rectangle()
    {

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

    void Rectangle::setOutputLabel(string o)
    {
      outputLabel = o;
    }
    string Rectangle::getOutputLabel() const
    {
      return outputLabel;
    }
