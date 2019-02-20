#include <iostream>
using namespace std;
/// The getMax() function returns the maximum
/// integer in the sequence of n integers pointed
/// by p.
int main()
{
 int y = 4;
 int &r = y; // r is an alias of y
 cout << "The value of y is: " << y << endl;
 cout << "The value of r is: " << r << endl;
 cout << "The address of y is: " << &y << endl;
 cout << "The address of r is: " << &r << endl; // Display the address of y
}
