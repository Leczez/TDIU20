#include <iostream>
#include <utility>

using namespace std;

class Banknote
{
  // You will need to fill in all aspects of the class, for this
  // special scenario including copy construction from modifiable
  // reference, move construction and copy assignment from modifiable
  // reference, and operator to convert to int
public:
  Banknote(int n): value{n}, used{false}
  {
      cout << "Raised $" << value << endl;
  }

  ~Banknote()
  {
      if(!used &&value > 0)
      {
          std::cout << "Lost: $" << value << endl;
      }
  }

  Banknote(Banknote &input): value{input.value}, used{false}
  {
      input.value = 0;
      input.used  = true;
  }

  Banknote(Banknote &&input): value{input.value}, used{false}
  {
      input.value = 0;
      input.used  = true;
  }
  Banknote& operator=(Banknote &rhs)
  {
      return *this;
  }
  operator int()
  {
      return value;
  }
private:
    int value;
    bool used;
};

// NO CHANGES BELOW THIS LINE!

Banknote purchase_goat(Banknote payment)
{
  if ( payment > 100 )
  {
    cout << "Enough money ($" << payment << ") for a goat!" << endl;
    return Banknote{ payment - 100 };
  }
  else
  {
    cout << "Insufficient money ($" << payment << ") for a goat!" << endl;
    return payment;
  }
}

int main()
{
  Banknote a{150}; // Raised $150
  Banknote b{50};  // Raised $50

  {
    Banknote c{ purchase_goat(a) }; // $150 is enough, raises $50 in exchange to "c" and lost $150
    Banknote d{ purchase_goat(c) }; // $50 not enough, $50 exchange transferred to "d"
  } // lost $50 from "d"

  Banknote e{ purchase_goat(a) }; // no value left in "a"
  Banknote f{ purchase_goat(b) }; // $50 not enough, $50 exchange transferred to "e"

  return 0; // lost $50 from "f"
}

// Example output (connect to comments above)
//
// Raised:150
// Raised:50
// Enough money ($150) for a goat!
// Raised:50
// Lost:150
// Insufficient money ($50) for a goat!
// Lost:50
// Insufficient money ($0) for a goat!
// Insufficient money ($50) for a goat!
// Lost:50
