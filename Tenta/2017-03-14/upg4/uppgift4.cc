#include <iostream>
#include <utility>

#include "stack.h"

using namespace std;

void print_stack(Stack && s)
{
  while ( ! s.empty() )
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main()
{
  Stack a;
  Stack b;

  cout << "Mata in heltal, avsluta med Ctrl+D: ";
  for ( int n; cin >> n; )
  {
    a.push(n);
  }
  cin.clear();

  cout << "Mata in heltal, avsluta med Ctrl+D: ";
  for ( int n; cin >> n; )
  {
    b.push(n);
  }

  /*{
    Stack c{a};
    a = b;
    b = c;
 }*/

  //swap(a, b);
  Stack c{a};
  cout << "Du matade först in talen (här i omvänd ordning):" << endl;
  print_stack(move(a));
  cout << "Du matade sedan in talen (här i omvänd ordning):" << endl;
  print_stack(move(b));
  cout << "KOPIA:" << endl;
  print_stack(move(c));
  return 0;
}
