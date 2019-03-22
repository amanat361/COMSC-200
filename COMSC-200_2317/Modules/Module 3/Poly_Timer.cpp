/*
Timer ---> UpwardCounter ---> MultCounter ---> ExpoCounter

OR

Timer ---> UpwardCounter ---> MultCounter
           |
           |
           ExpoCounter

Timer holds the setting and current variables that are passed down to the other functions.
UpwardCounter modifies the ticker and the done function to go up instead of down.
MultCounter also modifies those functions to multiple instead of add.
Expo changes the variables as well as adds new functionality which multiplies by exponents.
*/
#include <iostream>
using namespace std;

class Timer
{
  protected:
  int setting;
  int current;
  public:
  Timer(int s)
  {
    setting = s;
    current = s;
  }
  virtual void OneTick()
  {
    current--;
  }
  virtual bool Done() const
  {
    return (current == 0);
  }
  virtual void Reset()
  {
    current = setting;
  }
  void Go()
  {
    while (this->Done() == false)
    {
      cout << current << "*";
      this->OneTick();
    }
    cout << "ding!";
  }
};

class UpwardCounter : public Timer
{
  public:
    UpwardCounter(int s) : Timer(s)
    {
      current = 0;
    }
    virtual void OneTick()
    {
      current++;
    }
    virtual bool Done() const
    {
      return (current >= setting);
    }
    virtual void Reset()
    {
      current = 0;
    }
};

class MultCounter : public UpwardCounter
{
  protected:
    int mult;
  public:
    MultCounter(int s, int m) : UpwardCounter(s)
    {
      mult = m;
      current = 1;
    }
    virtual void OneTick()
    {
      current = current * mult;
    }
    virtual bool Done() const
    {
      return (current >= setting);
    }
    virtual void Reset()
    {
      current = 1;
    }
};

class ExpoCounter : public MultCounter
{
public:
    ExpoCounter(int s, int m = 1) : MultCounter(s,m)
    {
        current = 1;
    }
    virtual void OneTick()
    {
        mult++;
        current = mult * mult;
    }
    virtual void Reset()
    {
        mult = 1;
        current = 1;
    }
};

int main()
{
  cout << endl << "Part 1" << endl;
  Timer timerA(4);
  timerA.Go();
  cout << endl << endl;

  cout << "Part 2" << endl;
  UpwardCounter upB(4);
  upB.Go();
  cout << endl << endl;

  cout << "Part 3" << endl;
  MultCounter multC(3, 2);
  multC.Go();
  cout << endl << endl;

  cout << "Part 4" << endl;
  MultCounter multD(20, 3);
  multD.Go();
  cout << endl << endl;

  cout << "Part 5" << endl;
  timerA.Reset();
  timerA.Go();
  cout << endl << endl;

  cout << "Part 6" << endl;
  upB.Reset();
  upB.Go();
  cout << endl << endl;

  cout << "Part 7" << endl;
  multD.Reset();
  multD.Go();
  cout << endl << endl;

  cout << "Part 8" << endl;
  ExpoCounter ecE(100);
  ecE.Go();
  cout << endl << endl;

  return 0;
}
