#include "PhoneMgr.h"
#include <iostream>  // for using cin and cout
#include <cstdlib>   // for using atoi()
#include <fstream>   // for processing input files
#include <string>
#include <time.h>

using namespace std;

PhoneMgr::PhoneMgr()
{
  fstream inputFile;
  long long number;
  int pos;
  string numberString, firstName, lastName, line, name;
  string fileName = "phonenumbers.txt";
  inputFile.open(fileName);

  while (getline(inputFile, line))
  {
       arrPhone[recordCount] = new Phone;
       numberString = line.substr(0, 10);
       name = line.substr(22, ' ');
       pos = name.find(' ');
       firstName = name.substr(0, pos);
       lastName = name.substr(pos + 1, sizeof(name));
       number = stoll(numberString);

       arrPhone[recordCount]->setPhoneNumber(number);
       arrPhone[recordCount]->setFirstName(firstName);
       arrPhone[recordCount]->setLastName(lastName);

       recordCount++;
  }

  inputFile.close();
}

PhoneMgr::~PhoneMgr()
{
  for (int i = 0; i < recordCount; i++)
  {
    if (arrPhone[i] != nullptr)
    {
      delete arrPhone[i];
    }
  }
}

void PhoneMgr::Display()
{
  for (int i = 0; i < recordCount; i++)
  {
    cout << i + 1 << ".) ";
    cout << arrPhone[i]->getPhoneNumber();
    cout << " ";
    cout << arrPhone[i]->getFirstName();
    cout << " ";
    cout << arrPhone[i]->getLastName();
    cout << endl;
  }
  cout << endl;
}

void PhoneMgr::Random()
{
  srand (time(NULL));
  int randomNumber = rand()%recordCount;

  cout << randomNumber + 1 << ".) ";
  cout << arrPhone[randomNumber]->getPhoneNumber();
  cout << " ";
  cout << arrPhone[randomNumber]->getFirstName();
  cout << " ";
  cout << arrPhone[randomNumber]->getLastName();
  cout << endl << endl;
}

void PhoneMgr::Dial(int x)
{
  cout << x << ".) ";
  x--;
  cout << arrPhone[x]->getPhoneNumber();
  cout << " ";
  cout << arrPhone[x]->getFirstName();
  cout << " ";
  cout << arrPhone[x]->getLastName();
  cout << endl << endl;
}

int PhoneMgr::getRecordCount() const
{
    return recordCount;
}
