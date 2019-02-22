#include <iostream> //console outout
#include <cstdlib> //random number generation

using namespace std;

//array size to be used globally in all functions
const int SIZE = 10;

//create double pointer array with random numbers
int ** getRandomInt()
{
  //use time seed for random numbers
  srand(time(NULL));

  //create and initialize double pointer array
  int ** pp;
  pp = new int*[SIZE];

  //fill array with random numbers (0-10)
  for (int i = 0; i < SIZE; i++)
  {
    pp[i] = new int;
    *pp[i] = rand()%10;
  }

  //send the array to main
  return pp;
}

//display the contents of the double pointer array
void displayInt(int ** pp)
{
  //index array and output
  for (int i = 0; i < SIZE; i++)
  {
    if (i < SIZE - 1)
    {
      cout << *pp[i] << ", ";
    }
    //output last index with endl instead of comma
    else
    {
      cout << *pp[i] << endl;
    }
  }
}

//release memory and delete all indexes of the array
void deleteInt(int ** pp)
{
  for (int i = 0; i < SIZE; i++)
  {
    if (pp[i] != nullptr)
    {
      delete pp[i];
    }
  }
}

int main()
{
  int ** pp = getRandomInt(); //create double pointer array
  displayInt(pp); //output contents of double pointer array
  deleteInt(pp); //dereference data in double pointer array

  return 0;
}
