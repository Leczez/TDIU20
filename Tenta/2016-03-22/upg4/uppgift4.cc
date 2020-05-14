#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Payment_Method
{
protected:
  Payment_Method(string i, bool e)
    : issuer{i}, electronic{e} {}

public:
  virtual string name() const { return "Payment_Method"; }
  virtual void print() const
  {
    string e_str{};
    if ( electronic )
      e_str = " (electronic)";
    else
      e_str = " (real money)";
    cout << name() << e_str << ": " << issuer << "; ";
  }

  Payment_Method(Payment_Method const&) = delete;
  Payment_Method& operator=(Payment_Method const&) = delete;

private:
  string issuer;
  bool electronic;
};

class Distributed_PM : public Payment_Method
{
public:
  Distributed_PM(string i, double v, bool e = false)
    : Payment_Method{i,e}, nominal_value{v} {}

  Distributed_PM(Distributed_PM const&) = delete;
  Distributed_PM& operator=(Distributed_PM const&) = delete;

  string name() const override { return "Distributed_PM"; }
  void print() const = 0;

protected:
  double nominal_value;
};

class Coin : public Distributed_PM
{
public:
  Coin(string i, double nv, double rv)
    : Distributed_PM{i, nv}, real_value{rv} {}

  Coin(Coin const&) = delete;
  Coin& operator=(Coin const&) = delete;

  string name() const override { return "Coin"; }
  void print() const override
  {
    Payment_Method::print();
    cout << "nominal value = " << nominal_value << "; "
         << "real value = " << real_value << "; " << endl;
  }

private:
  double real_value;
};

class Account_PM : public Payment_Method
{
public:
  Account_PM(string i, string o)
    : Payment_Method{i, true}, owner{o} {}

  Account_PM(Account_PM const&) = delete;
  Account_PM& operator=(Account_PM const&) = delete;

  string name() const override { return "Account_PM"; }
  void print() const = 0;

protected:
  string owner;
};

class Card : public Account_PM
{
public:
  Card(string i, string o, string n)
    : Account_PM{i, o}, number{n} {}

  Card(Card const&) = delete;
  Card& operator=(Card const&) = delete;

  string name() const override { return "Card"; }
  void print() const override
  {
    Payment_Method::print();
    cout << "owner = " << owner << "; "
         << "number = '" << number << "'; ";
  }

private:
  string number;
};

int main()
{
// Should print:
//  Card (elektronic): VISA; owner = Kim; number = '4711 0123 9876 0001';
//  Coin (real money): Riksbanken; nominal value = 10; real value = 0.12;
//  Card (elektronic): MasterCard; owner = Sam; number = '012 347 110';
//  Coin (real money): Riksbanken; nominal value = 5; real value = 0.13;
  const Card visa{"VISA", "Kim", "4711 0123 9876 0001"};
  const Card master{"MasterCard", "Sam", "012 347 110"};
  const Coin sek10{"Riksbanken", 10.00, 0.12};
  const Coin sek5{"Riksbanken", 5.00, 0.13};

  vector<Payment_Method const*> pmv;
  pmv.push_back(&visa);
  pmv.push_back(&sek10);

  pmv.push_back(&master);
  pmv.push_back(&sek5);

  for ( Payment_Method const* pm : pmv )
  {
    pm->print();
    cout << endl;
  }

// Should not be possible
//  Card c = card;
//  Account_PM apm("Kim", "1234");

  return 0;
}
