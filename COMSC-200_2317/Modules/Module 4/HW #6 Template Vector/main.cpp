/* Write your answers to the questions at the top of the main.cpp

Question 1: Why normally the entire template class, including both the declaration and
implementation, are placed in the .h file? If we choose to implementation the definition
of the class be in the .cpp file, what should be the way to include it?

Answer 1:

Question 2: Taking the getQuotient() function as example, what may go wrong when using this template?

Answer 2:
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

template <typename randomType>
randomType randomPick(randomType x, randomType y, randomType z)
{
  srand(time(0));
  int randomNumber = rand()%3;

  if (randomNumber == 0) return x;
  else if (randomNumber == 1) return y;
  else return z;
}

template <typename correspondingType>
correspondingType getChoice(string s1, string s2, correspondingType a, correspondingType b)
{
  bool invalid = true;
  string userInput;

  while (invalid)
  {
    cout << "Please pick " << s1 << " or " << s2 << ": ";
    cin >> userInput;
    if (userInput != s1 && userInput != s2) cout << "Invalid input..." << endl;
    else invalid = false;
  }

  if (userInput == s1) return a;
  else return b;
}

template <class T>
class UniqueList
{
private:
  vector <T> vec;
  bool isValid;
public:
  void insert(T x)
  {
    if (vec.size() > 0)
    {
      for (int i = 0; i < vec.size(); i++)
      {
        if (x == vec.at(i)) isValid = false;
        else isValid = true;
      }
    }
    if (isValid) vec.push_back(x);
  };

  void display()
  {
    for (int i = 0; i < vec.size(); i++)
    {
      cout << vec.at(i) << endl;
    }
  };

  int Size()
  {
    return vec.size();
  };

  T getFirst()
  {
    return vec.at(0);
  };

  T getLast()
  {
    return vec.at(vec.size() - 1);
  };

  T getMin()
  {
    T min = vec.at(0);
    for (int i = 1; i < vec.size(); i++)
    {
      if (vec.at(i) < min) min = vec.at(i);
    }
    return min;
  };
};

int main()
{
  cout << "Part 1" << endl;
  cout << randomPick('1', '2', '3') << endl;
  cout << randomPick(11, 22, 33) << endl;
  cout << randomPick("Mac", "PC", "Others") << endl << endl;

  cout << "Part 2" << endl;
  cout << getChoice("x", "y", 1, 2) << endl << endl;

  cout << "Part 3" << endl;
  /*
  UniqueList <string> u;
  u.insert("11");
  u.insert("12");
  u.insert("23");
  u.insert("40");
  u.insert("9");
  u.insert("12");
  u.display();
  */

  UniqueList <int> u;
  u.insert(5);
  u.insert(10);
  u.insert(10);
  u.insert(20);
  u.insert(3);
  u.insert(3);
  u.insert(23);
  u.insert(5);
  u.insert(27);
  u.display();

  cout << "The size of UniqueList is " << u.Size() << endl;
  cout << "The first element of UniqueList is " << u.getFirst() << endl;
  cout << "The last element of UniqueList is " << u.getLast() << endl;
  cout << "The min element of UniqueList is " << u.getMin() << endl << endl;

  return 0;
}
