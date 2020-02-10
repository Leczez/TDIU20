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
    int operator[](int index);
    void insert(int const N) const;
    void remove(int const N) const;
    int size();

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
    
    class List_iterator
    {
    public:
        List_iterator();


    private:
        List::Element* pos{};

    };


    //Element* tmp{};
    Element* begin() const;
    Element* end() const;
    Element* first{};
    Element* last{};
};
