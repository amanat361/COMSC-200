#include <iostream>
#include <map>

using namespace std;

int main()
{
  //create a map container with key char and element int
  map<char,int> myMap;

  //insert two different pairs
  myMap.insert(pair<char, int>('z',200));
  myMap.insert(pair<char, int>('a',100));

  //no fucking clue cheif
  pair<map<char,int>::iterator,bool>ret;

  //uhhhhhh
  ret = myMap.insert(pair<char,int>('z',500));

  //basically seeing if that key has been used before ('z')
  if (ret.second == false)
  {
    cout << "element 'z' already existed";
    cout << " with a value of " << ret.first->second << endl;
  }
  else cout << "It is inserted" << endl;

  //dunno what the it does but the other things insert more values
  map<char,int>::iterator it = myMap.begin();
  myMap.insert(it, pair<char,int>('b',400));
  myMap.insert(it, pair<char,int>('c',300));

  //make a new map with values up until z in the other one
  map<char,int> myMap2;
  myMap2.insert(myMap.begin(), myMap.find('z'));

  //output first map
  cout << "myMap contains: " << endl;
  for (it = myMap.begin(); it != myMap.end(); it++)
  {
    cout << it->first << " => " << it->second << endl;
  }
  cout << endl;

  //output second map
  cout << "myMap2 contains: " << endl;
  for (it = myMap2.begin(); it != myMap2.end(); it++)
  {
    cout << it->first << " => " << it->second << endl;
  }
}
