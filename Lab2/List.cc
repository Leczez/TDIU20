#include "List.h"
#include <stdexcept>
#include <vector>

using namespace std;

List::List()
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;
}


List::~List()
{
    std::cout << "KALLADE PÅ LISTDESTRUKTOR" << endl;
    delete first;
    delete last; //KAN TA BORT DENNA OCH KOMMENTERA UT ANDRA IFSATSEN I ELEMENTDESTRUKTORN. Då tar "delete first" hand om last.
}


List::List(initializer_list<int> data)
{
    vector<int> input{data};
    for(unsigned int i{};i < input.size();i++)
    {
        insert(input[i]);
    }
}

List::Element::Element(int N):
value{N}
{}

List::Element::~Element()
{
    std::cout << "KALLADE PÅ ELEMENTDESTRUKTOR" << endl;
    if(this->next != nullptr) //CHECK SO WE DO NOT DELETE LAST SENTINEL
    {
        if(this->next->next != nullptr) // CHECK SO WE DO NOT DELETE FIRST SENTINEL
        {
            delete this->next;
        }
    }
}


void List::insert(int const N)
{
    Element* temp{first->next};
    Element* new_box = new Element{N};

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

    temp->next = nullptr; //SO THE DESTRUCTOR DOESNT TAKE THE WHOLE LIST WITH ITSELF
    temp->prev = nullptr;
    delete temp;
}

ostream& operator<<(ostream& os, List const& l)
{
    List::Element* temp{l.first};
    while(temp->next != l.last)
    {
        os << temp->next->value;
        temp = temp->next;
        if(temp->next != l.last) // stops it from writing a space in the last output
        {
            os << " ";
        }
    }
    return os;
}
