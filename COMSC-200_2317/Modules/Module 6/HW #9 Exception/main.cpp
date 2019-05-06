#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct Student{
  int ssn;
  string name;
  char gender;
};

class StudentMgr
{
  //hfdgkjdhgjerkgh
  private:
    vector<Student> sList;
    vector<int> temp;

    void insertStudent(int, string, char);
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
  fstream inputFile;
  string fileName = "students.txt";
  string line;

  inputFile.open(fileName);
  while (getline(inputFile, line))
  {
    int len = line.length();

    for (int i = 0; i < len; i++)
    {
      line[i] = tolower(line[i]);
      if (!isalnum(line[i]) && line[i] != ' ')
      {
        line.erase(i,1);
        len--;
        i--;
      }
    }

    Student temp;
    temp.ssn = 123;
    temp.name = line;
    temp.gender = 'F';

    sList.push_back(temp);
  }
  inputFile.close();




  /// TO DO: Add your code here
  ///
  /// In each iteration of awhileloopdo the following:/
  //       1. Use getline() to read one line of data in students.txt
  ///      2. Use the code in parseString() to decompose the data tokens.
  ///         And save the data tokens in alocal vector.(This is the vector sList.)
  ///      3. Conduct an action. An action isone the following
  ///         'I' -Insert the record. Use push_back to add the record to the end
  ///         of thevectorsList.
  ///         'U' -Update the record
  ///         'D' -Delete the record
  ///
  ///  Sort the vector after all records are added.
}

StudentMgr::~StudentMgr()
{

}

void StudentMgr::insertStudent (int ssn, string ame, char gender)
{
  /// TO DO: Add your code here
}

void StudentMgr::updateStudent (int ssn, string ame,char gender)
{
  /// TO DO: Add your code here
}

void StudentMgr::deleteStudent (int ssn)
{
  /// TO DO: Add your code here
}

void StudentMgr::displayStudent(int ssn)
{
  bool studentFound = false;
  int x;
  for (x = 0; x < sList.size() - 1; x++)
  {
    if (ssn == (sList.at(x)).ssn) studentFound = true;
  }
  if (studentFound) cout << (sList.at(x)).name << endl;
  else cout << "Student not found" << endl;
}

void StudentMgr::displayAll()
{
  for (int i = 0; i < sList.size() - 1; i++)
  {
    cout << (sList.at(i)).name << endl;
  }
}

int StudentMgr::findStudentIndex(int ssn)
{
  /// TO DO: Add your code here
  /// Binary search should be conducted
  /// If the record cannot be found, throw an integer -1 here to signal that
  /// an exception has occurred.
}

void StudentMgr::sortBySSN()
{
  /// TO DO: Add your code here
}

int main()
{
  StudentMgr sm;
  char input;

  do
  {
    cout << endl << endl << "Select an option:" << endl;
    cout << "-----------------" << endl << endl;

    cout << "A. Display all student info" << endl;
    cout << "S. Display specific student" << endl;
    cout << "Q. Quit the program" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter selection: ";
    cin >> input;
    cin.clear();
    cin.ignore(32768, '\n');
    input = tolower(input);

    switch (input)
    {
      case 'a':
        sm.displayAll();
        sm.sortBySSN();
        cout << endl << endl << "sorted" << endl << endl;
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
