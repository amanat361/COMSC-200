//Samin Amanat
//Tsai
//COMSC-200 Midterm Code
//March 29, 2019

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;

class Ship
{
protected:
  int serialNumber = 0;
  string type = "";
  string name = "";
  int year = 0;
public:
  void setSerialNumber(int x)
  {
    serialNumber = x;
  }
  void setShipName(string s)
  {
    name = s;
  }
  void setYearBuilt(int x)
  {
    year = x;
  }

  virtual void setDataOther(int x) = 0;
  virtual void display() = 0;
};

class CargoShip : public Ship
{
private:
  int cargo;
public:
  CargoShip()
  {
    type = "Cargo";
  }

  void setDataOther(int x)
  {
    cargo = x;
  }

  void display()
  {
    cout << "Serial Number: " << serialNumber << endl;
    cout << "Ship Type: " << type << endl;
    cout << "Ship Name: " << name << endl;
    cout << "Year built: " << year << endl;
    cout << "Cargo Capacity: " << cargo << endl << endl;
  }
};

class CruiseShip : public Ship
{
private:
  int passengers;
public:
  CruiseShip()
  {
    type = "Cruise";
  }

  void setDataOther(int x)
  {
    passengers = x;
  }

  void display()
  {
    cout << "Serial Number: " << serialNumber << endl;
    cout << "Ship Type: " << type << endl;
    cout << "Ship Name: " << name << endl;
    cout << "Year built: " << year << endl;
    cout << "Passenger Capacity: " << passengers << endl << endl;
  }
};

class ShipMgr
{
private:
  Ship * arrShips[SIZE] = {nullptr};
public:
  ShipMgr()
  {
    buildShips();
  }
  ~ShipMgr()
  {
    delete[] arrShips[0];
    delete[] arrShips[1];
  }
  void buildShips()
  {
    arrShips[0] = new CargoShip;
    arrShips[0]->setSerialNumber(10);
    arrShips[0]->setShipName("O_O_P");
    arrShips[0]->setYearBuilt(2019);
    arrShips[0]->setDataOther(999);
    arrShips[0]->display();

    cout << "----------" << endl << endl;

    arrShips[1] = new CruiseShip;
    arrShips[1]->setSerialNumber(20);
    arrShips[1]->setShipName("Cruisey McCruiseShip");
    arrShips[1]->setYearBuilt(1999);
    arrShips[1]->setDataOther(23);
    arrShips[1]->display();
  }
};

int main()
{
  ShipMgr sm;
  return 0;
}
