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
    delete first;
    delete last;
}


List::List(initializer_list<int> data)
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;

    vector<int> input{data};
    for(unsigned int i{};i < input.size();i++)
    {
        insert(input[i]);
    }
}


List::List(List const &l)
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;

    Element* temp{l.first};
    while(temp->next != l.last)
    {
        insert(temp->next->value);
        temp = temp->next;
    }
}


List::List(List &&l) noexcept
{
    last  = std::exchange(l.last, nullptr);
    first = std::exchange(l.first, nullptr);
}


List& List::operator=(List const &l)
{

    Element* temp{l.first};
    while(temp->next != l.last)
    {
        insert(temp->next->value);
        temp = temp->next;
    }
    return *this;
}

List& List::operator=(List &&l) noexcept
{
    last  = std::exchange(l.last, nullptr);
    first = std::exchange(l.first, nullptr);
    return *this;
}


int List::size()
{
    Element* temp{first};
    int size{};
    while(temp->next != last)
    {
        ++size;
        temp = temp->next;
    }
    return size;
}



int List::operator[](int index)
{
    Element* temp{first};
    for(int i{};i < index + 1;i++)
    {
        temp = temp->next;
        if(temp == last)
        {
            throw out_of_range{"index out of range"};
        }
    }
    return temp->value;
}



void List::insert(int const N) const
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


void List::remove(int const N) const
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

List::Element::Element(int N):
value{N}
{}

List::Element::~Element()
{
    if(this->next != nullptr)
    {
        if(this->next->next != nullptr)
        {
            delete this->next;
        }
    }
}

List::List_iterator List::begin()
{
    List_iterator temp{};
    //temp.pos = reinterpret_cast<List::List_iterator::Element*>(first);
    temp.pos = first->next;
    return temp;
}
List::List_iterator List::end()
{
    List_iterator temp{};
    //temp.pos = reinterpret_cast<List::List_iterator::Element*>(last);
    temp.pos = last->prev;
    return temp;
}


List::List_iterator::List_iterator(): pos{nullptr}
{}

List::List_iterator::List_iterator(Element* ptr): pos{ptr} //HJÄLPFUNKTION
{}

List::List_iterator& List::List_iterator::operator=(List::List_iterator const &it)
{
     pos = it.pos;
     return *this;
}

List::List_iterator&  List::List_iterator::operator++()
{
    if(pos->next != nullptr)
    {
        pos = pos->next;
        return *this;
    }
    else
    {
        throw out_of_range{"Index out of range"};
    }
}
bool List::List_iterator::operator==(List::List_iterator const &it) const
{
    return (pos == it.pos);
}

bool List::List_iterator::operator!=(List::List_iterator const &it) const
{
    return (pos != it.pos);
}

int  List::List_iterator::operator*() const
{
    return pos->value;
}
