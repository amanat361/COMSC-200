/*
Question 1: Why normally the entire template class, including both the declaration and
implementation, are placed in the .h file? If we choose to implementation the definition
of the class be in the .cpp file, what should be the way to include it?

Answer 1: This is because with a template class, the entire class is compiled at compile time for
the program to use as a fully compiled function. Because of this, since it is not runtime polymorphism like
overriding, where we use inherited classes, the compiler needs both the declaration and the implementation
of the function all together. If we choose to implement the definition of the class in the .cpp file, then
we would need to also put the implementation in the .cpp file for the compiler to compile the function.

Notes from template module: There is one important difference between a regular class and a class template.
When we use regular classes, we separate the declaration in a .h file and the implementation in a .cpp file.
However, when we use class templates, we put the entire class in the header file because without it, the
entire object code for the class cannot be completed.

//---------------//---------------//---------------//---------------//---------------//---------------//

Question 2: Taking the getQuotient() function as example, what may go wrong when using this template?

Answer 2: This is because one of the limitations of having a template function is that the template
parameters must ALL be of the same type. A quotient is the result of a division, and the user may want to
divide two integers but the function will have an integer output making it not an actual division, it would
only be able to work with doubles or floating point integers. This is because template functions get their
return type from the first instance of that variable. For example, if you had:
  template <typename exampleType>
  exampleType func(exampleType x, int y)
  {
    return x;
  }
  int main()
  {
    func(1.0, 1);
  }
This example will call func as a double return type function, and will return a double, as te first instance
of exampleType is a double (1.0). This is the same as rewriting the function to look like this:
  double func(double x, int y);
Because of this, the user may have trouble getting the result they would like with a getQuotient function. A
workaround to this would be template type specifiers which I believe we will learn about soon.
*/

#include <iostream>         //console input and output
#include <stdlib.h>      //random number functionality
#include <time.h>    //time seed for the random number
#include <vector> //to use vectors and their functions

using namespace std;

//Random pick function that takes three values of any (same) type, and chooses one to return
template <typename R>
R randomPick(R x, R y, R z)
{
  int randNum = rand()%3; //generate number

  if (randNum == 0) return x;
  else if (randNum == 1) return y;
  else return z;
}

//Corresponding function that prompts two strings and outputs one of the (any type but same type) variables
template <typename C>
C getChoice(string s1, string s2, C a, C b)
{
  bool invalid = true;
  string userInput;

  while (invalid) //loop until user inputs either s1 or s2
  {
    cout << "Please pick " << s1 << " or " << s2 << ": ";
    getline (cin, userInput);
    if (userInput != s1 && userInput != s2) cout << "Invalid input..." << endl;
    else invalid = false;
  }

  cout << "Your corresponding value is: ";
  if (userInput == s1) return a;
  else return b;
}

//Unique List Template Class
template <class T>
class UniqueList
{
private:
  vector <T> vec; //the class holds the vector
  bool isValid; //checks for vector duplicates
public:
  void insert(T x)
  {
    isValid = true;
    for (int i = 0; i < vec.size(); i++)
    {
      if (x == vec.at(i))
      {
        cout << "Repeated value discovered: " << x << " (already at index " << i << ")" << endl;
        isValid = false;
      }
    }
    if (isValid) vec.push_back(x); //insert value if valid (not repeated)
  };

  void display()
  {
    cout << endl;
    if (vec.size() == 0) cout << "The vector is empty." << endl;
    else for (int i = 0; i < vec.size(); i++) cout << vec.at(i) << endl;
    cout << endl;
  };

  int Size() {return vec.size();};
  T getFirst() {return vec.at(0);};
  T getLast() {return vec.at(vec.size() - 1);};

  T getMax()
  {
    T max = vec.at(0);
    for (int i = 0; i < vec.size(); i++) if ((vec.at(i)) > max) max = vec.at(i);
    return max;
  };
  T getMin()
  {
    T min = vec.at(0);
    for (int i = 0; i < vec.size(); i++) if ((vec.at(i)) < min) min = vec.at(i);
    return min;
  };
};

int main()
{
  //TIME SEED
  srand(time(NULL));

  //PART ONE RANDOM PICK
  cout << "Part 1 - Random Pick" << endl << endl;
  cout << randomPick('1', '2', '3') << endl;
  cout << randomPick(11, 22, 33) << endl;
  cout << randomPick(123.321, 321.123, 500.005) << endl;
  cout << randomPick("Mac", "PC", "Others") << endl << endl;

  //PART TWO CORRESPONDING PICK
  cout << "Part 2 - Corresponder" << endl << endl;
  cout << getChoice("x", "y", 1, 2) << endl;
  cout << getChoice("a", "b", 'a', 'b') << endl;
  cout << getChoice("1", "2", "One", "Two") << endl;
  cout << getChoice("option 1", "option 2", 7873.89, 1300.14) << endl << endl;

  //PART THREE UNIQUE LIST
  cout << "Part 3 - Unique List" << endl << endl;
  cout << "List \"Fruits\":" << endl << endl;
  UniqueList <string> u; //create the list
  u.insert("Banana"); //insert value into list
  u.insert("Apple"); //insert value into list
  u.insert("Guava"); //insert value into list
  u.insert("Guava"); //insert value into list
  u.insert("Strawberry"); //insert value into list
  u.insert("Orange");  //insert value into list
  u.insert("Pear"); //insert value into list
  u.display();   //display the unique list
  cout << "The list size is "     << u.Size()     << endl;
  cout << "The first element is " << u.getFirst() << endl;
  cout << "The last element is "  << u.getLast()  << endl;
  cout << "The max element is "   << u.getMax()   << endl;
  cout << "The min element is "   << u.getMin()   << endl << endl;

  cout << "List \"Integers\":" << endl << endl;
  UniqueList <int> t; //create the list
  t.insert(500); //insert value into list
  t.insert(600); //insert value into list
  t.insert(700); //insert value into list
  t.insert(100); //insert value into list
  t.insert(100); //insert value into list
  t.insert(150);  //insert value into list
  t.insert(450); //insert value into list
  t.display();   //display the unique list
  cout << "The list size is "     << t.Size()     << endl;
  cout << "The first element is " << t.getFirst() << endl;
  cout << "The last element is "  << t.getLast()  << endl;
  cout << "The max element is "   << t.getMax()   << endl;
  cout << "The min element is "   << t.getMin()   << endl << endl;
}
