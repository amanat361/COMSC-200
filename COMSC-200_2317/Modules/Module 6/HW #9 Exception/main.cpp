#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Student
{
  int ssn;
  string name;
  char gender;
};

void deleteBlanks(string &);
string getName(string &);
bool checkSSN(string);
string getFirstThingy(string &);
Student splitMeUp(string, string &);

class StudentMgr
{
  private:
    vector<Student> sList;

    void insertStudent(Student);
    void updateStudent(int, string, char);
    void deleteStudent(int);

    int findStudentIndex(int); //binary search using SSN
    void sortBySSN();

  public:
    StudentMgr();
    ~StudentMgr();

    void displayStudent(int);
    void displayAll();
};

StudentMgr::StudentMgr()
{
  bool boo = true;
  bool foo = true;
  Student stud;
  string funcCall;
  fstream inputFile;
  string fileName = "students.txt";
  string line;

  inputFile.open(fileName);
  while (getline(inputFile, line))
  {
    boo = true;
    do {
      boo = false;
      try
      {
        stud = splitMeUp(line, funcCall);
      }
      catch(string hmmNotThis)
      {
        cout << "Exception made for: " << hmmNotThis << endl;
        getline(inputFile, line);
        while (foo)
        {
          if (line == "\0" || line == "\n" || line == "\r") getline(inputFile, line);
          else boo = false;
        }
        boo = true;
      }
    } while(boo);

    if (funcCall == "i")
    {
      try { insertStudent(stud); }
      catch(string hmmNotThis) { cout << hmmNotThis << endl; }
    }
    else if (funcCall == "u")
    {
      try { updateStudent(stud.ssn, stud.name, stud.gender); }
      catch(string hmmNotThis) { cout << hmmNotThis << endl; }
    }
    else if (funcCall == "d")
    {
      try { deleteStudent (stud.ssn); }
      catch(string hmmNotThis) { cout << hmmNotThis << endl; }
    }
    getline(inputFile, line);
    while (line == "\r" || line == "\n") { getline(inputFile, line); };
  }

  inputFile.close();
}

StudentMgr::~StudentMgr()
{

}

Student splitMeUp(string splitMe, string &funcCall)
{
  Student stud;
  string s;

  deleteBlanks(splitMe);
  s = getFirstThingy(splitMe);
  funcCall = s;

  deleteBlanks(splitMe);
  s = getFirstThingy(splitMe);

  bool isDigit = checkSSN(s);
  if (isDigit) stud.ssn = stoi(s);
  else
  {
    string hmmNotThis;
    hmmNotThis = "Sorry pal, your ssn (" + s + ") isn't a valid int ):";
    throw hmmNotThis;
  }

  deleteBlanks(splitMe);
  s = getName(splitMe);
  stud.name = s;

  deleteBlanks(splitMe);
  s = getFirstThingy(splitMe);
  stud.gender = *s.c_str();

  return stud;
}

void deleteBlanks(string &deleteMe)
{
  while (deleteMe[0] == ' ') deleteMe = deleteMe.substr(1);
}

string getFirstThingy(string &token)
{
  string head = "";
  while (token[0] != ' ' && token[0] != '\0')
  {
    head = head + token.substr(0,1);
    token = token.substr(1);
  }
  return head;
}

string getName(string &token)
{
  string head = "";
  head = head + token.substr(0,1);
  token = token.substr(1);
  while (token[0] != '\"')
  {
    head = head + token.substr(0,1);
    token = token.substr(1);
  }
  head = head + token.substr(0,1);
  token = token.substr(1);
  return head;
}

void StudentMgr::insertStudent (Student stud)
{
  int x = findStudentIndex(stud.ssn);

  if (x == -1)
  {
    sList.push_back(stud);
    sortBySSN();
  }
  else
  {
    string hmmNotThis;
    hmmNotThis = "Uh oh buddy, " + to_string(stud.ssn) + " already existssss )):::";
    throw hmmNotThis;
  }
}

void StudentMgr::updateStudent (int ssn, string name, char gender)
{
  int x = findStudentIndex(ssn);
  if (x != -1)
  {
    sList[x].ssn = ssn;
    sList[x].name = name;
    sList[x].gender = gender;
  }
}

void StudentMgr::deleteStudent (int ssn)
{
  int x = findStudentIndex(ssn);

  if (x != -1) sList.erase(sList.begin() + x);
  else
  {
    string hmmNotThis;
    hmmNotThis = "Woah there human!!!, " + to_string(ssn) + " does NOOOT exiist!!!!! wooooo";
    throw hmmNotThis;
  }
}

void StudentMgr::displayStudent(int ssn)
{
  int x = findStudentIndex(ssn);

  cout << "Student sOCIaL SeCuRiTy nUMbEr: " << sList[x].ssn << endl;
  cout << "Student Name: " << sList[x].name << endl;
  cout << "Student g e n d e r: " << sList[x].gender << endl;
}

void StudentMgr::displayAll()
{
  for(vector<Student>::iterator it=sList.begin(); it!=sList.end(); ++it)
  {
      cout << "sOCIaL SeCuRiTy nUMbEr: " << it->ssn << endl;
      cout << "Name: " << it->name << endl;
      cout << "G e n d e R: " << it->gender << endl;
  }
}

int StudentMgr::findStudentIndex(int ssn)
{
  //hi professor i haven't done binary search since comsc-110
  //sorry if it's really bad

  int leftSideIThink = 0; //???
  int thisShouldProbabyBeTheRightSide = sList.size() - 1;

  while (leftSideIThink <= thisShouldProbabyBeTheRightSide)
  {
    int currentValue = thisShouldProbabyBeTheRightSide - leftSideIThink;
    currentValue /= 2;
    currentValue += leftSideIThink;

    if (sList[currentValue].ssn == ssn) // if we found gold!!!
    {
      return currentValue; //yeehaw;
    }
    if (sList[currentValue].ssn < ssn) leftSideIThink = currentValue + 1;
    else thisShouldProbabyBeTheRightSide = currentValue - 1;
  }

  return -1; //this tells our other functions that we couldn't find it ):
}

bool ssnComparison(Student one, Student two)
{
  if (one.ssn > two.ssn) return true;
  else return false;
}

void StudentMgr::sortBySSN()
{
  sort(sList.begin(), sList.end(), ssnComparison);
}

bool checkSSN(string s)
{
  for (int banana = 0; banana < s.size(); banana++)
  {
    if (!isdigit(s[banana])) return false;
  }
  return true;
}

int main()
{
  StudentMgr sm;
  char input;

  do
  {
    cout << endl << endl;
    cout << "Select an option:"           << endl;
    cout << "---------------------------" << endl;
    cout << "A. Display all student info" << endl;
    cout << "S. Display specific student" << endl;
    cout << "Q. Quit the program"         << endl;
    cout << "---------------------------" << endl;
    cout << "Enter selection: ";
    cin >> input;
    cin.clear();
    cin.ignore(32768, '\n');
    input = tolower(input);

    switch (input)
    {
      case 'a':
        sm.displayAll();
        break;
      case 's':
      {
        cout << "Input SSN: ";
        int ssn;
        cin >> ssn;
        cin.clear();
        cin.ignore(32768,'\n');
        sm.displayStudent(ssn);
        break;
      }
    }
  } while (input!='q');
  return 0;
}
