#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <initializer_list>

//TODO: 5-4 - Läs rättningsprotokollet.
//TODO: Era remove och insert funktioner ska inte vara const.
//Det kompilerar om man sätter const efter som ingen medlem
//direkt modifieras, men insert och remove modifierar listan
//så därför ska de inte vara const.

class List
{
private:
    class Element
    {
    public:
        Element() = default;
        Element(int N);
        ~Element() = default;

        Element(Element const &) = delete;
        Element(Element &&) = delete;
        Element& operator=(Element const &) = delete;
        Element& operator=(Element &&) = delete;

        Element* next{nullptr};
        Element* prev{nullptr};
        int value{};
    };

    Element* first{};
    Element* last{};

public:
    List();
    ~List();
    List(std::initializer_list<int> const &data);
    List(List const &l);
    List(List &&l);

    List& operator=(List const &l);
    List& operator=(List &&l);

    int operator[](int const index) const;
    
    void insert(int const N) const;
    void remove(int const N) const;
    int size() const;
    friend std::ostream& operator<<(std::ostream& os, List const& l);

    class List_iterator
    {
    public:
        friend class List;
        List_iterator& operator=(List_iterator const &) = default;

        List_iterator& operator++();
        bool operator==(List_iterator const &it) const;
        bool operator!=(List_iterator const &it) const;
        int  operator*() const;

    private:
        List_iterator() = default;
        Element* pos{};
    };

    List_iterator begin() const;
    List_iterator end() const;
};
#endif
