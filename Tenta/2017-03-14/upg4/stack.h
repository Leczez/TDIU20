#ifndef STACK_H_
#define STACK_H_

class Stack
{
public:
  Stack();
  ~Stack();
  Stack(Stack const &st);
  Stack(Stack &&st);
  Stack& operator=(Stack const &st);
  Stack& operator=(Stack &&st);
  bool empty() const;
  void push(int const&);
  void pop();
  int top() const;

private:

  class Element
  {
  public:
    Element(int const& i, Element* n = nullptr);

    int data;
    Element* next;
  };

  Element* first;
};


class Empty_Stack : public std::out_of_range
{
    using out_of_range::out_of_range;

};

#endif
