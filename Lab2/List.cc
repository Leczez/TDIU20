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

void List::remove(int const N)
{
    Element* temp{first};
    for(int i{}; i < N;i++)
    {   
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
}

ostream& operator<<(ostream& os, List const& l)
{
    List::Element* temp{l.first};
    while(temp->next != nullptr)
    {
        os << temp->next->value;
        temp = temp->next;
        if(temp->next != nullptr)
        {
            os << " ";
        }
    }
    return os;
}