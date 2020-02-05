#include <iostream>


class List
{
public:
    List();
    
    void insert(int const N);


    

private:
    class Element
    {
    public:
        Element() = default;
        Element(int N);
        Element* next{nullptr}; // default värde för pointer = nullptr
        Element* prev{nullptr};
        int value{};
    };
    //Element* tmp{};
    Element* first{}; // first och last pekarna ska inte kunna ändras (const)
    Element* last{};
};
ostream& operator<<(ostream& os, List& list);