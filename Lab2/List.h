#include <iostream>
#include <initializer_list>

class List
{
public:
    List();
    ~List();
    List(std::initializer_list<int> input);

    void insert(int const N);
    void remove(int const N);


    friend std::ostream& operator<<(std::ostream& os, List const& l);

private:
    class Element
    {
    public:
        Element() = default;
        Element(int N);
        ~Element();
        Element* next{nullptr};
        Element* prev{nullptr};
        int value{};
    };
    //Element* tmp{};
    Element* first{}; // first och last pekarna ska inte kunna ändras (const)
    Element* last{};
};
