///  Sample 1
///  Following is a simple example to show exception handling in C++.
///  The output of program explains flow of execution of try/catch blocks.
///
///  Step 1:
///     Test 2 cases: (1) x = 0; (2) x = -1
///     Which test case throws an exception?
///
///  Step 2:
///     Change "catch (int y )" to "catch (string y )".
///     Will the code in catch block be executed? Why?
///
#include <iostream>
using namespace std;

int main()
{
   int x = 0;

   // Some code
   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int y ) {
      cout << "Exception Caught. y: " << y << endl;
   }

   cout << "After catch (Will be executed) \n";
   return 0;
}

/// Sample 2
/// There is a special catch block called ‘catch all’ catch(…) that can be used to catch all
/// types of exceptions. For example, in the following program, an int is thrown as an exception,
/// but there is no catch block for int, so catch(…) block will be executed.
///
/// 1. Test by adding another catch (as shown below) to the code and see what difference it makes.
///               catch (int x)  {
///                         cout << "Caught " << x ;
///                }
/// 2. Change
///         throw 10;
///    to
///         throw "10";
///    and test again. What error do you get? How can we fix the bug?
///
/*#include <iostream>
#include <string>

using namespace std;

int main()
{
    try  {
       throw 10;
    }
    catch (const char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}*/

/// Sample 3
/// The throw statement can be in a function which is called inside the try block.
///
/*
#include <iostream>

using namespace std;

int getBalance(int, int);

int main()
{
   int num1, num2;
   int balance = 0;

   cout << "Enter two numbers: ";
   cin >> num1 >> num2;

   // Divide num1 by num2 to catch any potential exceptions.
   try
   {
       balance = getBalance(num1, num2);

       cout << "The balance is " << balance << endl;

   }
   catch (char * exceptionString)
   {
     cout << "The exception message: \"" << exceptionString << "\"\n";
   }
    catch (int x)
   {
     cout << "The exception message: \"" << x << "\"\n";
   }


   cout << "End of the program. \n";
   return 0;
}

///
/// The getBalance function deducts currBalance by withdrawnAmt.
/// If new balance is less than zero, the function throws an exception.
///

int getBalance(int currBalance, int withdrawnAmt)
{
    if (currBalance - withdrawnAmt < 0)
        throw (currBalance - withdrawnAmt);

   return int (currBalance - withdrawnAmt);
}

*/
