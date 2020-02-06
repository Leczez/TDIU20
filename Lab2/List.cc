#include "List.h"
#include <stdexcept>
#include <vector>

using namespace std;

List::List()
{
    first = new Element{};
    last = new Element{};
    first->next = last;
    last->prev = first;
}

List::List(initializer_list<int> data)
{
    vector<int> input{data};
    for(int i{};i < input.size();i++)
    {
        insert(input[i]);
    }
}

List::Element::Element(int N):
value{N}
{}

void List::insert(int const N)
{
    Element* temp{first->next};
    Element* new_box = new Element{N};
/*    if(temp->next->next == nullptr)
    {
        new_box->next = temp->next->next
        temp->next = new_box;
    }
*/
    while(temp != last || temp->prev == first)
    {
        if(N <= temp->value || temp == last)
        {
            new_box->next = temp;
            new_box->prev = temp->prev;
            temp->prev->next = new_box;
            temp->prev = new_box;

            temp = last;
        }
        else
        {
            temp = temp->next;
            if(temp == last)
            {
                new_box->next = temp;
                new_box->prev = temp->prev;
                temp->prev->next = new_box;
                temp->prev = new_box;
            }
        }
    }

}

void List::remove(int const N)
{
    Element* temp{first};
    for(int i{}; i < N+1;i++)
    {
        temp = temp->next;
        if(temp == last)
        {
            throw out_of_range{"index out of range"};
        }
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

ostream& operator<<(ostream& os, List const& l)
{
    List::Element* temp{l.first};
    while(temp->next != l.last)
    {
        os << temp->next->value;
        temp = temp->next;
        if(temp->next != l.last)
        {
            os << " ";
        }
    }
    return os;
}
