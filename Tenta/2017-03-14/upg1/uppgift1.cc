#include <iostream>

#include "ebook.h"

using namespace std;

#include "text.h"

int main()
{
  {
    Ebook book{::dummy, 25, 15};
    
    cout << book.next_page() << endl;
    book.set_page_size(35, 25);
    cin.ignore();
    cout << "== page boundary ==" << endl;
    
    cout << book.next_page() << endl;
    book.set_page_size(30, 20);
    cin.ignore();
    
    while ( ! book.at_end() )
    {
      cout << "== page boundary ==" << endl;
      cout << book.next_page() << endl;
      cin.ignore();
    }
  }
  
  {
    Ebook book{::lorem};
    
    cout << book.next_page() << endl;
    book.set_page_size(25, 15);
    cin.ignore();
    cout << "== page boundary ==" << endl;
    
    cout << book.next_page() << endl;
    book.set_page_size(60, 30);
    cin.ignore();
    
    while ( ! book.at_end() )
    {
      cout << "== page boundary ==" << endl;
      cout << book.next_page() << endl;
      cin.ignore();
    }
  }
  
  return 0;
}
