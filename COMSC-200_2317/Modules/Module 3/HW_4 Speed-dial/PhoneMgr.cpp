#include "PhoneMgr.h"

using namespace std;

//constructor
PhoneMgr::PhoneMgr()
{
  //DATA
  fstream inputFile;
  long long number;
  int pos;
  string numberString, firstName, lastName, line, name;
  string fileName = "phonenumbers.txt";
  inputFile.open(fileName);

  //read phonenumbers.txt and do the folliwng:
    //make a contact and use each line from the file for data
    //separate it into phone number, first name, and last name
    //store this data within the phone object
  while (getline(inputFile, line))
  {
     //make new phone object in phone manager array
     arrPhone[recordCount] = new Phone;

     //extract phone number from line (0-10 as a number is 10 digits)
     numberString = line.substr(0, 10);

     //extract full name from line
     name = line.substr(22, ' ');

     //find point between first and last name
     pos = name.find(' ');

     //separate first and last name from name
     firstName = name.substr(0, pos);
     lastName = name.substr(pos + 1, sizeof(name));

     //convert number from string to long long
     number = stoll(numberString);

     //store all of this data in the phone object
     arrPhone[recordCount]->setPhoneNumber(number);
     arrPhone[recordCount]->setFirstName(firstName);
     arrPhone[recordCount]->setLastName(lastName);

     //increase record count of number of phones
     recordCount++;
  }

  inputFile.close();
}

//destructor
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
  //headers
  cout << "Index Phone Number " << "First Name" << " " << "Last Name" << endl;
  cout << "===== ============ " << "==========" << " " << "=========" << endl;

  //contacts
  for (int i = 0; i < recordCount; i++)
  {
    //index
    if ((i + 1) < 10) cout << "00";
    else if ((i + 1) < 100) cout << "0";
    cout << (i + 1) << ".)  ";

    //phone number
    cout << arrPhone[i]->getPhoneNumber();

    //first name
    cout << "  " << arrPhone[i]->getFirstName();

    //last name
    int indent = (11 - (arrPhone[i]->getFirstName()).length());
    for (int x = 0; x < indent; x++) cout << " ";
    cout << arrPhone[i]->getLastName();
    cout << endl;
  }

  //formatting
  cout << endl;
}

void PhoneMgr::Random()
{
  //create random index within range
  srand (time(NULL));
  int randomNumber = rand()%recordCount;

  //output contact with labels
  cout << "Dialing...";
  cout << arrPhone[randomNumber]->getPhoneNumber();
  cout << " @ ";
  cout << arrPhone[randomNumber]->getFirstName();
  cout << " ";
  cout << arrPhone[randomNumber]->getLastName();
  cout << endl;
  cout << "*ring*...*ring*";
  cout << endl << endl;
}

void PhoneMgr::Dial(int x)
{
  //convert user input into array index (0 vs. 1)
  x--;
  //output contact with labels
  cout << "Dialing...";
  cout << arrPhone[x]->getPhoneNumber();
  cout << " @ ";
  cout << arrPhone[x]->getFirstName();
  cout << " ";
  cout << arrPhone[x]->getLastName();
  cout << endl;
  cout << "*ring*...*ring*";
  cout << endl << endl;
}

int PhoneMgr::getRecordCount() const
{
    return recordCount;
}
