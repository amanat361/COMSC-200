/*

Step 1
Explain what doubleIt() is for? What will happen if we remove the "&"?

doubltIt() basically doubles the width and height of the Rectangle
we use & to modify the object passed, as it does not return anything
if we take away the & we can not modify the original object

Step 2
Comment out the following line in class Rectangle
               friend Rectangle doubleIt(Rectangle&);
     What will happen? What error message will we get?

     errors: functions that differ only in their return type cannot be overloaded

Step 3
If we do not want to use friend function, what is the other technical approach to conduct the task?
Complete the work and compare the pros and cons of these two approaches.

we can make a setter function as a part of the class or just remove the friend keyword so the class has a public function

pros to making a public funciton within the class - do not need to use friend and only objects of class can use it
pros to making a friend function outside of class - any other object outside of the class can use that function

Step 4
Uncomment these two lines:
  // Rectangle foo = bar;
  // cout << "foo After: " << foo.area() << '\n';
What will be displayed?

it just displays the same thing as bar after displays (the new rectangle area) as it copies the data from bar to foo

Step 5
Uncomment these two lines:
  //Rectangle * p = TenTime(bar);
  //cout << "After: " << p->area() << '\n';

Implement a function named TenTime() which increases both width and height to 10 time as big.
      In main(), call this function and then display its area again to see if TenTime() works as expected.

  now it is displayed with an area of 2400 (100 * the previous area)

*/
#include <iostream>
using namespace std;

class Rectangle {
  private:
    long long width, height;
  public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}

    long long area() {return width * height;}
    long long getWidth(){return width;}
    long long getHeight(){return height;}

    friend void doubleIt(/*const*/ Rectangle&);
    friend Rectangle * TenTime(/*const*/ Rectangle&);
};

void doubleIt(/*const*/ Rectangle& param)
{
  param.width = param.width*2;
  param.height = param.height*2;

  return;
}

Rectangle * TenTime(/*const*/ Rectangle& param)
{
  param.width = param.width*3;
  param.height = param.height*3;

  return &param;
}

int main ()
{
  Rectangle bar (2,3);
  cout << "Before (bar made)" << endl;
  cout << "Width: " << bar.getWidth() << endl;
  cout << "Height: " << bar.getHeight() << endl;
  cout << "Area: " << bar.area() << endl << endl;

  doubleIt(bar);
  cout << "After (bar doubled)" << endl;
  cout << "Width: " << bar.getWidth() << endl;
  cout << "Height: " << bar.getHeight() << endl;
  cout << "Area: " << bar.area() << endl << endl;

  Rectangle foo = bar;
  cout << "After (foo is bar)" << endl;
  cout << "Width: " << foo.getWidth() << endl;
  cout << "Height: " << foo.getHeight() << endl;
  cout << "Area: " << foo.area() << endl << endl;

  Rectangle * p = TenTime(bar);
  cout << "After (p is TenTime(bar))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  p = TenTime(*p);
  cout << "After (p is TenTime(p))" << endl;
  cout << "Width: " << p->getWidth() << endl;
  cout << "Height: " << p->getHeight() << endl;
  cout << "Area: " << p->area() << endl << endl;

  return 0;
}
