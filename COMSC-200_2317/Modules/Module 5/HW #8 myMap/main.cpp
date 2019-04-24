#include <iostream>

using namespace std;

template <typename T1, typename T2>
class myMap
{
public:
  myMap *next;
  bool insert(pair<T1,T2> pa)
  {
    bool b = false;
    // TO DO: Add code here
  };
  int * find(char c)
  {
    // TO DO: Add code here
  };
  int * begin()
  {
    // TO DO: Add code here
  };
  int * end()
  {
    return nullptr;
  };
  void display()
  {
    for(auto it = myMap.begin(); it != myMap.end(); ++it)
    {
      cout << it->first << " -> " << it->second << endl;
    }
  };
};

int main()
{
  myMap <char,int> mp1;

  mp1.insert(pair<char,int>('z',900));
  mp1.insert(pair<char,int>('a',100));
  mp1.insert(pair<char,int>('c',300));

  bool ret = mp1.insert(pair<char,int>('z',500)); // Should fail bc exists

  if (!ret) cout << "Element 'z' already existed." << endl;
  else cout << "Element 'z' has been inserted." << endl;

  mp1.find('c');
  mp1.find('x');
}
