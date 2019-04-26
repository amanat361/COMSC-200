#include <iostream>

using namespace std;

template <typename T1, typename T2>
class myMap
{
private:
  struct List
  {
    pair<T1,T2> pa;
    List* next;
  };
public:
  myMap *next;

  /*
  Similar to the isnert() function of map in STL.
  The only difference is that it returns T or F
  to indicate if the new element is inserted.
  */

  bool insert(pair<T1,T2> pa)
  {
    bool b = false;

    return b;
  };

  /*
  Similar to the find() function of the map in STL.
  The only difference is that the returned value is a
  pointer which points to the element if the key is found.
  If the key is not found, the returned value is nullptr.
  */

  int * find(char c)
  {
    int * p;
    return p; //template for using pointers in future
  };

  /*
  If the map is not empty, then it returns the pointer
  which points to the first element of the map. Otherwise,
  it return nullptr.
  */

  int * begin()
  {
    int * p;
    return p; //template for using pointers in future
  };

  /*
  It returns nullptr.
  */

  int * end()
  {
    return nullptr;
  };

  void display()
  {
    //we will use pointer instead of iterator here
  };
};

int main()
{
  /*
  myMap <char,int> mp1;

  mp1.insert(pair<char,int>('z',900));
  mp1.insert(pair<char,int>('a',100));
  mp1.insert(pair<char,int>('c',300));

  bool ret = mp1.insert(pair<char,int>('z',500)); // Should fail bc exists

  if (!ret) cout << "Element 'z' already existed." << endl;
  else cout << "Element 'z' has been inserted." << endl;

  mp1.find('c');
  mp1.find('x');
  */
}
