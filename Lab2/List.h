#include <iostream>
#include <initializer_list>

class List
{
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

    Element* first{};
    Element* last{};
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

    class List_iterator// Användaren ska kunna deklarera objekt av denna typ och kunna: !=, ++ och =
    {
    public:
        friend class List; // Nu bör List komma åt allt i private hos List_iterator

        List_iterator();

        List_iterator& operator=(List_iterator const &it);
        List_iterator& operator++();
        List_iterator operator++(int);
        bool operator==(List_iterator const &it) const;
        bool operator!=(List_iterator const &it) const;
        int  operator*() const;


    private:
        List_iterator(Element* ptr); //HJÄLPFUNKTION
        Element* pos{};
        Element* first{first};
        Element* last{last};
    };
    List_iterator begin(); //t.ex. i Mainprogrammet: List_iterator it = lista.begin();
    List_iterator end();

};
