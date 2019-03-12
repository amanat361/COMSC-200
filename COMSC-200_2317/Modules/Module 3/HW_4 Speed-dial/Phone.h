#ifndef PHONE_H
#define PHONE_H

#include <iostream>  // for using cin and cout
#include <cstdlib>   // for using atoi() (note: in this program, atoi is outdated and stoi and stoll were used instead)
#include <fstream>   // for processing input files
#include <sstream>   // for using substring
#include <string>    // for using strings
#include <time.h>    //for random numbers
#include <cctype>
#include "stdlib.h"

using namespace std;

class Phone
{
private:
    long long phoneNumber;
    string firstName;
    string lastName;
public:
    Phone();
    ~Phone();
    void setFirstName(string);
    void setLastName(string);
    void setPhoneNumber(long long);
    string getFirstName() const;
    string getLastName() const;
    long long getPhoneNumber() const;
};

#endif // PHONE_H
