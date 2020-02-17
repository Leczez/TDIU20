#ifndef LIST_H
#define LIST_H
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

    int operator[](int index) const;
    void insert(int const N) const;
    void remove(int const N) const;
    int size() const;
    friend std::ostream& operator<<(std::ostream& os, List const& l);

    class List_iterator
    {
    public:
        friend class List;

        List_iterator();
        List_iterator& operator=(List_iterator const &it);
        List_iterator& operator++();
        bool operator==(List_iterator const &it) const;
        bool operator!=(List_iterator const &it) const;
        int  operator*() const;

    private:
        Element* pos{};
        Element* first{first};
        Element* last{last};
    };

    List_iterator begin() const;
    List_iterator end() const;
};
#endif
