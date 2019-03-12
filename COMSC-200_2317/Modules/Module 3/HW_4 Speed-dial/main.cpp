/// How does the use of the Manager class avoid memory leak?
/// Write your answer here.

#include "PhoneMgr.h"

using namespace std;

int main()
{
    //make phone manager pm
    string input;
    PhoneMgr pm;
    int recordCount = pm.getRecordCount();

    do
    {
        //output menu and prompt for choice
        cout << "------======MENU======------" << endl;
        cout << "Enter D to list all contacts" << endl;
        cout << "Enter R for a random contact" << endl;
        cout << "Enter Q to quit this program" << endl;
        cout << "Enter # for contact (1 to " << recordCount << ")" << endl << endl;
        cout << "Please input your choice: ";
        cin >> input;
        cout << endl;

        //display contacts
        if (input == "D" || input == "d") pm.Display();

        //random contact
        else if (input == "R" || input == "r") pm.Random();

        //quit program
        else if (input == "Q" || input == "q") return 0;

        //dial contact
        else
        {
          //convert input to integer and dial if within range
          if (stoi(input) > 0 && stoi(input) <= recordCount)
          {
            pm.Dial(stoi(input));
          }
          //prompt user that contact is out of range
          else
          {
            cout << "The conact must be within the range of the list." << endl << endl;
          }
        }
    }while(input != "Q" && input != "q");

    return 0;
}
