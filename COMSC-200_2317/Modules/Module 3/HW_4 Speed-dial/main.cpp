/// How does the use of the Manager class avoid memory leak?
/// Write your answer here.

#include <iostream>
#include "PhoneMgr.h"
#include <stdlib.h>   /// For using atoi()
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    string input;
    PhoneMgr pm;
    int recordCount = pm.getRecordCount();

    do
    {
        cout << "------======-MENU-======------" << endl;
        cout << "Enter D to list all contacts." << endl;
        cout << "Enter R for a random contact." << endl;
        cout << "Enter Q to quit this program." << endl;
        cout << "Or, enter a contact between 1 and " << recordCount << "." << endl << endl;
        cout << "Input your choice: ";
        cin >> input;
        cout << endl;
        if (input == "D" || input == "d")
          pm.Display();
        else if (input == "R" || input == "r")
          pm.Random();
        else if (input == "Q" || input == "q")
        {
          return 0;
        }
        else
        {
          if (stoi(input) > 0 && stoi(input) < recordCount)
          {
            pm.Dial(stoi(input));
          }
          else
          {
            cout << "The conact must be within the range of the list." << endl << endl;
          }
        }
    }while(input != "Q" && input != "q");

    return 0;
}
