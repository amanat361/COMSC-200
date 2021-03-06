//   Samin Amanat
// Professor Tsai
// COMSC-200-2317
//  Feb. 15, 2019

/*
(1) Should we delete the data stored in studArr1? Why?
	No, you do not need to delete all of the data. You can unallocate it with:
		delete[] studArr1;
	This will release the memory but not delete the data stored within it.
	The reason that we do not need to delete the data stored in studArry1 is:
	In an object array, the data is going to be deleted automatically when
	the program ends, and the entire array gets released at the same time.

(2) Should we delete the data stored in studArr2? Why?
	Yes, we have to delete the data stored in studArr2 to free up space in the system as
	deleting all of the data indivually is the only way to release the array, since each
	piece of the array is a pointer. In order to be able to delete each pointer, we have
	to check if it is null. Each element has to be checked first. If it is not NULL, we
	release the memory. As apposed to studArr1, each node (piece of data in the array)
	has to be released from memory if it is not null. This is because the data is not
	automatically released when the program terminates.

	When we delete the pointers, do we actually release the memory which was allocated for
		(1) the studArr2 array
			No.
		(2) the pointer stored in the array
			No.
		(3) the student objects pointed by the pointers?
			No.

	The "delete" command does not release memory for any of these things.
	What it does is free up memory to be able to be used for other things.

	A good analogy I've heard before is:
		Think of memory as a big warehouse with lots of boxes (memory) to put things into.
		When we call "new", the warehouse staff finds an unused box large enough for our needs.
		They give the box a number so we can put our stuff in it, that number is like a pointer.
		When we "delete" that pointer, this box is available again, but doesn't belong to you.
		There could still be your stuff inside of the box, or someone else's, or nothing at all.
		The box still exists and is not destroyed, just the ID they put on it or the "pointer".
		In terms of this assignment, when the pointers in the array are destroyed, the memory for:
		the studArr2, the pointer stored in the array, and the student objects, are not released.
*/

#include "pch.h"
#include <iostream> //Console input and output
#include <string>   //To use the string variable type

using namespace std;

//Student structure
struct student
{
	//DATA
	int ID = 0;
	string name = "";
	long long phone = 0;
	string addr = "";
};

int main()
{
	//Student object array (type 1)
	const int SIZE = 10;
	student * studArr1 = nullptr;
	studArr1 = new student[SIZE];

	//Output the size of the array
	cout << "The size of studArr1 is: " << sizeof(studArr1) << endl;

	//Hard coded data for student #1 in studArr1
	studArr1[0].ID = 12345;
	studArr1[0].name = "Amy";
	studArr1[0].phone = 9256776789;
	studArr1[0].addr = "123 Main St, Livermore, CA, 94550";

	//Hard coded data for student #4 in studArr1
	studArr1[3].ID = 12666;
	studArr1[3].name = "Bill";
	studArr1[3].phone = 9256776000;
	studArr1[3].addr = "29 Johnson Dr, Livermore, CA, 94550";

	//Display the data in student array 1
	cout << "These are the contents of STUDENT ARRAY #1:" << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		//Check if the student exists by seeing if they have an ID
		if (studArr1[i].ID != 0)
		{
			cout << "Student #" << (i + 1) << " --- ";
			cout << "ID: " << studArr1[i].ID << ", ";
			cout << "Name: " << studArr1[i].name << ", ";
			cout << "Phone: " << studArr1[i].phone << ", ";
			cout << "Address: " << studArr1[i].addr;
			cout << endl;
		}
	}
	cout << endl;

	//Student pointer array (type 2)
	student * studArr2[SIZE];

	//Initialize the array with null pointers
	for (int i = 0; i < SIZE; i++)
	{
		studArr2[i] = nullptr;
	}

	//Output the size of the array
	cout << "The size of studArr2 is: " << sizeof(studArr2) << endl;

	//Hard coded data for student #1 in studArr2
	studArr2[0] = new student;
	studArr2[0]->ID = 12345;
	studArr2[0]->name = "Amy";
	studArr2[0]->phone = 9256776789;
	studArr2[0]->addr = "123 Main St, Livermore, CA, 94550";

	//Hard coded data for student #4 in studArr2
	studArr2[3] = new student;
	studArr2[3]->ID = 12666;
	studArr2[3]->name = "Bill";
	studArr2[3]->phone = 9256776000;
	studArr2[3]->addr = "29 Johnson Dr, Livermore, CA, 94550";

	//Display the data in student array 2
	cout << "These are the contents of STUDENT ARRAY #2:" << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		//Only output data if it's not null/empty
		if (studArr2[i] != nullptr)
		{
			cout << "Student #" << (i + 1) << " --- ";
			cout << "ID: " << studArr2[i]->ID << ", ";
			cout << "Name: " << studArr2[i]->name << ", ";
			cout << "Phone: " << studArr2[i]->phone << ", ";
			cout << "Address: " << studArr2[i]->addr;
			cout << endl;
		}
	}

	//Release data from studArr1
	delete[] studArr1;

	//Release data from studArr2
	for (int i = 0; i < SIZE; i++)
	{
		if (studArr2[i] != nullptr) delete studArr2[i];
	}

	return 0;
}
