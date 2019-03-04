/*
  Question 1. (5%): Why "indef RECTANGLE_H", "#define RECTANGLE_H" and "endif" have to be added to the .h file?
  Question 2. (5%): Why the size of the array, i.e. 21, must be a const?
  Question 3. (5%): Why we prefer to let the array hold pointers to Rectangle, instead of Rectangle objects?

  Answer 1:
    "indef", "define", and "endif" are things called header guards. The purpose of a header guard
    is to check if what comes after it, so in our case "RECTANGLE_H" is defined. If for example it
    is not defined, it continues on throughout the header file, where #define could define RECTANGLE_H.
    If the first header guard, "indef" comes out negative, meaning "RECTANGLE_H" was not defined, then
    the file would be blank. If not, it would include the code between it, and the #endif statement.
    What this is meant to do is prevent double declaration of any identifiers.
  Answer 2:
    There are multiple reasons and benefits to SIZE being a constand integer. For one, we have a dynamically
    allocated array here with objects created, and it would be detrimental if the size was accidentally
    modified, possibly causing problems in memory. Because of this, we use const to prevent the size from being
    accidentally modified. Also, when we use the display functions, in this program being displaySquares,
    displayVerticals, and displayHorizontals, we don't have to pass SIZE as a parameter.
  Answer 3:
    This is because we're using a pointer to an array of more pointers which point to objects instead of
    pointers that point to an array of objects. The main benefit to this is saving memory. A pointer is
    4 byted of memory compared to the object which takes up a lot more space. Let's say that not all
    of the array is filled up with objects. This is wasted space without using pointers instead of objects.
    When the program is run, the dynamically allocated memory can be filled as needed, saving memory. For example,
    the arrRect array holds a total of only 168 bytes of memory, while otherwise, it would take up a lot more,
    accounting for the size of the integers height and width, along with the counters, serial numbers, and
    output labels.
*/

#include "Rectangle.h"
using namespace std;

const int SIZE = 21;

void displaySquares(Rectangle *[]);
void displayVerticals(Rectangle *[]);
void displayHorizontals(Rectangle *[]);

int main()
{
    //Random number seed
    srand(time(NULL));

    //Create Rectangle array
    Rectangle * arrRect[SIZE];

    //Populate array with rectangles
    for (int i=0; i < SIZE; i++)
    {
         //Create rectangle with random width/height between 1-7
         arrRect[i] = new Rectangle(((rand()%7)+1), ((rand()%7)+1));
         Rectangle::totalRectangles++;

         //If rectangle meets criteria of type (i.e. square), increment counter of that rectangle type
         if (arrRect[i]->getWidth() == arrRect[i]->getHeight())
         {
           Rectangle::totalSquares++;
         }
         else if (arrRect[i]->getWidth() > arrRect[i]->getHeight())
         {
           Rectangle::totalHorizontals++;
         }
         else if (arrRect[i]->getWidth() < arrRect[i]->getHeight())
         {
           Rectangle::totalVerticals++;
         }
    }

    //Creat output label such as R0005 from a number like 5
    for (int i = 0; i < SIZE; i++)
    {
      if ((arrRect[i]->getSerialNumber()) < 10)      arrRect[i]->setOutputLabel("R000" + to_string(arrRect[i]->getSerialNumber()));
      else if ((arrRect[i]->getSerialNumber()) < 100) arrRect[i]->setOutputLabel("R00" + to_string(arrRect[i]->getSerialNumber()));
      else if ((arrRect[i]->getSerialNumber()) < 1000) arrRect[i]->setOutputLabel("R0" + to_string(arrRect[i]->getSerialNumber()));
    }

    //Display rectangles based on type
    displaySquares(arrRect);
    cout << endl;
    displayHorizontals(arrRect);
    cout << endl;
    displayVerticals(arrRect);
    cout << endl;

    //Delete array pointers / release memory
    for (int i = 0; i < SIZE; i++)
    {
      if (arrRect[i] != nullptr)
      {
        delete arrRect[i];
      }
    }
}

void displaySquares(Rectangle * arr[])
{
    cout << "Square" << endl;
    cout << "=======================" << endl;
    cout << "Label   Width   Height" << endl;
    for (int i = 0; i < SIZE; i++)
    {
      if (arr[i]->getWidth() == arr[i]->getHeight())
      {
        cout << arr[i]->getOutputLabel() << "       " << arr[i]->getWidth() << "        " << arr[i]->getHeight() << endl;
      }
    }
    cout << "=======================" << endl;
    cout << "Total: " << Rectangle::totalSquares << endl;
}

void displayVerticals(Rectangle * arr[])
{
  //output verticals
  cout << "Vertical Rectangle" << endl;
  cout << "=======================" << endl;
  cout << "Label   Width   Height" << endl;
  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i]->getWidth() < arr[i]->getHeight())
    {
      cout << arr[i]->getOutputLabel() << "       " << arr[i]->getWidth() << "        " << arr[i]->getHeight() << endl;
    }
  }
  cout << "=======================" << endl;
  cout << "Total: " << Rectangle::totalVerticals << endl;
}

void displayHorizontals(Rectangle * arr[])
{
  //output horizontals
  cout << "Horizonal Rectangle" << endl;
  cout << "=======================" << endl;
  cout << "Label   Width   Height" << endl;
  for (int i = 0; i < SIZE; i++)
  {
    if (arr[i]->getWidth() > arr[i]->getHeight())
    {
      cout << arr[i]->getOutputLabel() << "       " << arr[i]->getWidth() << "        " << arr[i]->getHeight() << endl;
    }
  }
  cout << "=======================" << endl;
  cout << "Total: " << Rectangle::totalHorizontals << endl;
}
