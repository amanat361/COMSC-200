#include "PhoneMgr.h"
#include <iostream>  // for using cin and cout
#include <cstdlib>   // for using atoi()
#include <fstream>   // for processing input files

using namespace std;

PhoneMgr::PhoneMgr()
{
          fstream inputFile;
          long long number;
          string firstName, lastName, temp;
          string fileName = "phonenumbers.txt";
          inputFile.open(fileName);

/// The array is already initialized with nullptr.
/// TO DO:
/// Populate the array by "newing" phone objects and save their pointers
/// in the array, and get the total record count of the input file.
/// Close input file to avoid memory leak.
}

PhoneMgr::~PhoneMgr()
{
    /// TO DO:
    /// Delete all pointers in the array to avoid memory leak.
}

void PhoneMgr::Display()
{
    /// TO DO:
    /// Display all phone numbers, first names and last names in three columns.
}

void PhoneMgr::Random()
{
    /// TO DO:
    /// Randomly display a phone number, its corresponding first name and last
    /// name in three columns
}

void PhoneMgr::Dial()
{
    /// TO DO:
    /// Get a number i from the user and display the phone number at the ith
    /// position, its corresponding first name and last name in three columns
    /// To the user, the first position is 1, not 0.
    /// You may have to add a parameter to the function.
}

int PhoneMgr::getRecordCount() const
{
    return recordCount;
}
