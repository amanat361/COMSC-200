#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//clean the text one line at a time by doing the following
// 1.) remove all non-alphanumeric charachters (excluding space)
// 2.) set every charachter to lowercase
// 3.) separate the line into multiple words
// 4.) push words into vector that is owned by readFile
void cleanText(vector <string> &vec, string line)
{
  int len = line.length();;
  string temp;

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

  //stringstream stream(line);

  for (int i = 0; i < len; i++)
  {
    //stream >> temp;
    vec.push_back(line);
    len = len - line.length();
  }
}

//read the file one line at a time and insert into map by doing this:
// 1.) read the file and get a line from the file
// 2.) send line to cleanText to be "cleaned up"
// 3.) transfer contents of vector to main map
//     a.) if it's in map, increase value (count) by one
//     b.) if not, set value (count) to one
// 4.) close input file
void readFile(map<string, int> &map)
{
  fstream inputFile;
  string fileName = "NotesBetweenTwoSisters.txt";
  string line;
  inputFile.open(fileName);

  while (getline(inputFile, line))
  {
    vector <string> vec;
    cleanText(vec, line);

    for (int i = 0; i < vec.size(); i++)
    {
      if (map.find(vec.at(i)) != map.end())
      {
        map[vec.at(i)]++;
      }
      else map[vec.at(i)] = 1;
    }
  }

  inputFile.close();
}

//display the contents of the map
void displayMap(map<string, int> &map)
{
  int display;
  for(auto it = map.begin(); it != map.end(); ++it)
  {
    display = 50 - it->first.length();
    cout << "Word: " << it->first;
    for (int i = 0; i < display; i++)
    {
      cout << ' ';
    }
    cout << " || " << "Occurences: " << it->second << endl;
  }
}

//create a map, fill it up, and then display it
int main()
{
  map<string,int> wordMap;
  readFile(wordMap);
  displayMap(wordMap);
}
