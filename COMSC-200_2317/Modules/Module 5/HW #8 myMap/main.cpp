#include <iostream>

using namespace std;

template <class C1, class C2>
class myMap
{
private:
  struct LinkedList
  {
    pair<C1,C2> pear;
    LinkedList * node;
  };
  LinkedList *head, *tail;
  bool headPtr;

public:

  //constructor
  myMap()
  {
    head = nullptr;
    tail = nullptr;
  };

  //destructor
  ~myMap()
  {
    if (head != nullptr) headPtr = false;
    else headPtr = true;

    while(!headPtr)
    {
      tail = head;
      head = head->node;
      delete tail;
      if (head != nullptr) headPtr = false;
      else headPtr = true;
    }
  };

  //insert
  bool insert(pair<C1,C2> v)
  {
    bool inserted = false;

    LinkedList * aList = new LinkedList;
    aList->pear = v;
    aList->node = nullptr;
    LinkedList * temp = nullptr;

    if (head != nullptr) headPtr = false;
    else headPtr = true;
    if (headPtr)
    {
      head = aList;
      inserted = true;
    }
    else
    {
      tail = head;

      while (tail != nullptr && tail->pear.first <= v.first)
      {
        if (tail->pear.first == v.first) return inserted;
        else
        {
          temp = tail;
          tail = tail->node;
        }
      }

      if (temp == nullptr)
      {
        aList->node = tail;
        head = aList;
        inserted = true;
      }
      else
      {
        temp->node = aList;
        aList->node = tail;
        inserted = true;
      }
    }
    return inserted;
  }; //insert

  //find (this function will return a pointer)
  int * find(char ch)
  {
    LinkedList * tail = head;
    if (head != nullptr) headPtr = false;
    else headPtr = true;
    if (!headPtr);

    while (tail != nullptr)
    {
      if (tail->pear.first == ch)
      {
        int * pt = new int;
        * pt = tail->pear.second;
        return pt;
      } //if
      else
      {
        tail = tail->node;
        if (tail == nullptr)
        {
          return nullptr;
        } // if
      } // else
    } // while
  }; // find

  //begin
  int * begin()
  {
    if (head != nullptr) headPtr = false;
    else headPtr = true;
    if (!headPtr)
    {
      int * pt = new int;
      *pt = head->pear.first;
      return pt;
    }
    else return nullptr;
  };

  //end
  int * end()
  {
    if (tail->node == nullptr) return nullptr;
  }

  //display
  void display()
  {
    tail = head;
    if (head != nullptr) headPtr = false;
    else headPtr = true;
    if (!headPtr);

    while (tail != nullptr)
    {
      cout << tail->pear.first << " ===>> " << tail->pear.second << endl;
      tail = tail->node;
    }
  };

}; // class myMap

int main()
{
    myMap <char,int> mp1;

    cout << "Beginning of myMap: " << mp1.begin() << endl << endl;

    mp1.insert( pair<char, int>('z', 900));
    mp1.insert( pair<char, int>('a', 100));
    mp1.insert( pair<char, int>('c', 300));

    bool ret = mp1.insert ( pair<char,int>('z', 500) );  /// This insertion should fail since the key exists
    if (ret == false) cout << "element 'z' already existed";
    else cout << "It is inserted.";

    cout << "Pointer at C is " << mp1.find('c') << endl << endl; // Return a pointer which points to the 'c' element
    cout << "Pointer at X is " << mp1.find('x') << endl << endl; // Return a nullptr to indicate that the element cannot be found.
    cout << "Beginning of myMap: " << mp1.begin() << endl << endl;
    cout << "End of myMap: " << mp1.end() << endl << endl;

    mp1.display();
  }
