#include "List.h"

using namespace std;

List::List()
{
    first = new Element{};
    last = new Element{};
    first->next = last;
    last->prev = first;
}
List::Element::Element(int N):
value{N}
{}

void List::insert(int const N)
{
    Element* temp{first};
    Element* new_box = new Element{N};
/*    if(temp->next->next == nullptr)
    {
        new_box->next = temp->next->next
        temp->next = new_box;
    }
*/

    while(temp != nullptr && temp->next != nullptr)
    {
        if(temp->next->value < N)
        {
            new_box->next = temp->next;
            new_box->prev = temp;
            temp->next = new_box;
            temp = nullptr;
        }
        else if(temp->next == nullptr)
        {
            new_box->prev = temp;
            temp->next = new_box;
        }
        else
        {
            temp = temp->next;
        }
    }

}


ostream& List::operator<<(ostream& os, List const &l)
{
    Element* temp{l.first};
    while(temp->next != nullptr)
    {
        os << temp->*next.value << ", ";
        temp = temp->next;
    }
    return os;
}
