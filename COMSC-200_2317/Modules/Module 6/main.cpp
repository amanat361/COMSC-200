#include <iostream>
#include <string>

using namespace std;

void parseString(string line)
{
  string quote = "\"";
  size_t pos = 0;
  string token;

  while ((pos = line.find(quote)) != string::npos)
  {
      token = line.substr(0, pos);
      cout << token << endl;

      line.erase(0, (quote.length()) + pos);

      if (line[0] == ' ')
      {
        line.erase(0,1);
      }

      if (line[(line.length())-1] == ' ')
      {
        line.erase((line.length())-1,1);
      }
  }
  cout << line << endl;
}

int main()
{
  string str1 = " \"Royal Caribbean International \" \" Jurre Van Wouw\" 1987\"For Sale ";
  parseString(str1);

  string str2 = " \" Royal Caribbean International \" \" Jurre Van Wouw\" 1987 \"For Sale\" 10\\02\\2009 ";
  parseString(str2);

  string str3 = "\" Royal Caribbean International \"\" Jurre Van Wouw\" 1987 ";
  parseString(str3);
}
