#include <stdexcept>
#include <utility>

#include "stack.h"

Stack::Stack() : first(nullptr)
{
}

Stack::~Stack()
{
    /*Element* victim{ first };
    while(!empty())
    {
        victim = first;
        first = first->next;
        delete victim;
    }
    first = nullptr;*/
}

Stack::Stack(Stack const &st): first{}
{
    Element* temp {st.first};
    while(temp != nullptr)
    {
        push(temp->data);
        first = temp;
        temp = temp->next;
    }
}

Stack::Stack(Stack &&st): first{}
{
    std::swap(first, st.first);
}

Stack& Stack::operator=(Stack const &st)
{
    (*this).~Stack();
    Stack Returner{st};
    std::swap((*this).first, Returner.first);
    return *this;
}

Stack& Stack::operator=(Stack &&st)
{
    (*this).~Stack();
    std::swap( (*this).first, st.first);
    return *this;
}


bool Stack::empty() const
{
  return first == nullptr;
}

void Stack::push(int const& i)
{
  first = new Element(i, first);
}

void Stack::pop()
{
  if ( empty() )
  {
    throw Empty_Stack("empty stack");
  }
  Element* victim{ first };
  first = victim->next;
  victim->next = nullptr;
  delete victim;
}

int Stack::top() const
{
  if ( empty() )
  {
    throw Empty_Stack("empty stack");
  }
  return first->data;
}

Stack::Element::Element(int const& i, Element* n)
  : data{i}, next{n}
{
}
