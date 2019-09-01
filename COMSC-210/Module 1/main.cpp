#include <iostream>
#include <string>

using namespace std;

struct Employee
{
  string name;
  double hours[5];
  double rate;
  double pay;
};

void initialize(Employee e[])
{
  string name;
  double hours[5], rate;
  for (int i = 0; i < 4; i++)
  {
    cout << "Last name of employee #" << i + 1 << ": ";
    cin >> name;
    cout << "Hours worked on Monday: ";
    cin >> hours[0];
    cout << "Hours worked on Tuesday: ";
    cin >> hours[1];
    cout << "Hours worked on Wednesday: ";
    cin >> hours[2];
    cout << "Hours worked on Thursday: ";
    cin >> hours[3];
    cout << "Hours worked on Friday: ";
    cin >> hours[4];
    cout << "Hourly rate of employee #" << i + 1 << ": ";
    cin >> rate;
    cout << endl;
    e[i].name = name;
    e[i].rate = rate;
    for (int j = 0; j < 5; j++)
    {
      e[i].hours[j] = hours[j];
    }
  }
}

void compute(Employee &e)
{
  int baseHours = 0, overHours = 0;
  for (int h = 0; h < 5; h++)
  {
    baseHours += e.hours[h];
  }
  if (baseHours > 40)
  {
    overHours = baseHours - 40;
    baseHours = 40;
  }
  e.pay = (baseHours * e.rate) + (overHours * (e.rate * 1.5));
}

void result(Employee e)
{
  cout << e.name << " payroll check ammount: $" << e.pay << endl;
}

int main()
{
  Employee employees[4];
  initialize(employees);
  for (int i = 0; i < 4; i++)
  {
    compute(employees[i]);
  }
  cout << endl;
  for (int i = 0; i < 4; i++)
  {
    result(employees[i]);
  }
}
