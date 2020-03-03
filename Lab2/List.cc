#include "List.h"
#include <stdexcept>
#include <utility>

using namespace std;
////////// LIST //////////////
List::List()
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;
}


List::~List()
{
    if(first != nullptr && last != nullptr)
    {
        Element* temp{first->next};
        while(temp != last)
        {
            temp = temp->next;
            delete temp->prev;
        }
        delete first;
        delete last;
        first = nullptr;
        last  = nullptr;
    }
}


//TODO: Ni kan läsa datat direkt från initializer_list med en for range loop. - OK
List::List(initializer_list<int> const &data)
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;

    for(int i : data)
    {
        insert(i);
    }
}
//TODO: Om ni ska använda er av insert i kopieringen så
//Ska ni gå baklänges genom listan.
//Då sätts värdet alltid in i början. - OK
List::List(List const &l)
{
    last = new Element{};
    first = new Element{};
    last->prev = first;
    first->next = last;

    Element* temp{l.last};
    while(temp->prev != l.first)
    {
        insert(temp->prev->value);
        temp = temp->prev;
    }
}

List::List(List &&l)
{
    last  = std::exchange(l.last, nullptr);
    first = std::exchange(l.first, nullptr);
}

//TODO: Den här kopieringen lägger till data i this.
//Det nuvarande datat ska skrivas över.
//Tex: l1 = {1,2}; l2 =  {3,4}; l2 = l1; => l2 = {1,2,3,4} - OK
List& List::operator=(List const &l)
{
    if(this != &l)
    {
        (*this).~List();
        last = new Element{};
        first = new Element{};
        last->prev = first;
        first->next = last;

        Element* temp{l.last};
        while(temp->prev != l.first)
        {
            insert(temp->prev->value);
            temp = temp->prev;
        }
    }
    return *this;
}

//Kommentar: Ni hade kunnat använda swap istället. -OK
List& List::operator=(List &&l)
{
    if(this != &l)
    {
        last  = std::exchange(l.last, last);
        first = std::exchange(l.first, first);
        l.~List(); //Destructs data which is swapped into the right hand side.
    }
    return *this;
}


int List::size() const
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


int List::operator[](int const index) const
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


void List::insert(int const N)
{
    Element* temp{first->next};
    Element* new_box = new Element{N};

    while(temp != last && temp->value <= N)
    {
        temp = temp->next;
    }
    new_box->next = temp;
    new_box->prev = temp->prev;
    temp->prev->next = new_box;
    temp->prev = new_box;
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
    if(l.first != nullptr && l.last != nullptr)
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
    }
        return os;
}

////////// ELEMENT ////////////////
List::Element::Element(int N): value{N}
{}
////////// LIST ITERATOR //////////
List::List_iterator List::begin() const
{
    List_iterator temp{};
    temp.pos = first->next;
    return temp;
}


List::List_iterator List::end() const
{
    List_iterator temp{};
    temp.pos = last;
    return temp;
}


List::List_iterator&  List::List_iterator::operator++()
{
    if(pos == nullptr)
    {
        throw out_of_range{"Uninitiated List_iterator"};
    }
    else if(pos->next == nullptr)
    {
        throw out_of_range{"Index out of range"};
    }
    else
    {
        pos = pos->next;
        return *this;
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


int List::List_iterator::operator*() const
{
    if(pos == nullptr)
    {
        throw out_of_range{"Uninitiated List_iterator"};
    }
    else if(pos->next == nullptr)
    {
        throw out_of_range{"Index out of range"};
    }
    else
    {
        return pos->value;
    }
}
