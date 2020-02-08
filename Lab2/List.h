#include <iostream>
#include <initializer_list>

class List
{
public:
    List();
    ~List();
    List(std::initializer_list<int> input);
    List(List const &l);
    List(List &&l) noexcept;
    List& operator=(List const &l);
    List& operator=(List &&l) noexcept;
    
    void insert(int const N) const;
    void remove(int const N) const;
    int  listsize();

    friend std::ostream& operator<<(std::ostream& os, List const& l);

private:
    class Element
    {
    public:
        Element() = default;
        Element(int N);
        ~Element();
        Element(Element const &) = default;
        Element(Element &&) = default;
        Element& operator=(Element const &) = default;
        Element& operator=(Element &&) = default;

        Element* next{nullptr};
        Element* prev{nullptr};
        int value{};
    };
    //Element* tmp{};
     Element* first{};
     Element* last{};
};
