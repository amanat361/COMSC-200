#include <iostream>
#include <vector>

using namespace std;

template <typename myType>
myType getMax (myType x, myType y)
{
  return (x > y? x: y);
}

int getMin()
{
  vector <int> vec;
  vec.push_back(10);
  vec.push_back(9);
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(9);
  vec.push_back(3);
  vec.push_back(4);

  int min = vec.at(0);
  for (int i = 1; i < vec.size(); i++)
  {
    if (vec.at(i) < min) min = vec.at(i);
  }
  return min;
};

int main()
{
  //cout << getMax("1","2") << endl;
  cout << getMin() << endl << endl;
}
