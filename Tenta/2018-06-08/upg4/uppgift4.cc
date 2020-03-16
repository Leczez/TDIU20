#include <iostream>
#include <random>
using namespace std;

class Plant
{
public:
  Plant() : size{1}, water{3}, air{3}, nutrient{3} {}

  void grow()
  {
    if ( is_alive() )
    {
      ++size;
      --nutrient;

      if ( --water < 1 )
        ++air;
    }
  }

  void give_water(int amount, int nutri = 0)
  {
    if ( water > 5 )
      --air;

    water += amount;
    nutrient += nutri;
  }

  void health() const
  {
    if ( ! is_alive() )
      cout << "Your plant is dead." << endl;
    else
      cout << "Your plant is " << size << " cm high and healthy." << endl;
  }

  bool is_alive() const
  {
    return ( air && water && nutrient );
  }

  int get_size() const
  {
    return size;
  }

private:
  int size; // cm
  int water;
  int air;
  int nutrient;
};


class Powerup
{
public:
    virtual ~Powerup() {};
    virtual void print(ostream &os) const = 0;
    virtual void apply_to(Plant &VAXT) const = 0;
private:
};

class Water: public Powerup
{
public:
    Water(int n) : amount_of_water{n} {}
    ~Water() {};
    void print(ostream &os) const override { os << amount_of_water << " Cups of Water" << endl; }
    void apply_to(Plant &VAXT) const override { VAXT.give_water(amount_of_water);}
private:
    int amount_of_water;
};

class Nutrient_Water: public Powerup
{
public:
    Nutrient_Water(int n, int m) : amount_of_water{n}, amount_of_nutrient{m} {}
    ~Nutrient_Water() {};
    void print(ostream &os) const override { os << amount_of_water << " Cups of Water and " << amount_of_nutrient << " Nutrients" << endl;}
    void apply_to(Plant &VAXT) const override { VAXT.give_water(amount_of_water, amount_of_nutrient);}
private:
    int amount_of_water;
    int amount_of_nutrient;
};

class Sunlight : public Powerup
{
public:
    Sunlight() = default;
    ~Sunlight() override{};
    void print(ostream &os) const override { os << "Sunlight" << endl; }
    void apply_to(Plant &VAXT) const override { VAXT.grow();}
private:
};


random_device rd;
mt19937 mt{rd()};
uniform_int_distribution<int> dist(1,3);

Powerup* create_powerup(int type)
{
  switch( type )
  {
    case 1: // Create new Water powerup
      return new Water( dist(mt) );

    case 2: // Create new Nutrient_Water powerup
      return new Nutrient_Water( dist(mt), dist(mt) );

    default: // Create new Sunlight powerup
      return new Sunlight();
  }
}

int main()
{
  Plant tamagothchi;

  int score{};
  while ( tamagothchi.is_alive() )
  {
    Powerup* p = create_powerup( dist(mt) );

    // Let user choose if to apply the powerup
    cout << endl << "New powerup available: ";
    p->print(cout);
    cout << "Apply? (y/n) ";
    string answer;
    getline(cin, answer);

    if ( answer.front() != 'n' )
    {
      p->apply_to(tamagothchi);
    }

    tamagothchi.health();
    score += tamagothchi.get_size();

    delete p;
  }
  cout << "You scored " << score << " points!" << endl;
  return 0;
}
