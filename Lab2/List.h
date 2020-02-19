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
    List(List &&l) noexcept;

    List& operator=(List const &l);
    List& operator=(List &&l) noexcept;

    int operator[](int const index) const;
    void insert(int const N) const;
    void remove(int const N) const;
    int size() const;
    friend std::ostream& operator<<(std::ostream& os, List const& l);

    class List_iterator
    {
    public:
        friend class List;
        List_iterator() = default;
        List_iterator& operator=(List_iterator const &) = default;

        List_iterator& operator++();
        bool operator==(List_iterator const &it) const;
        bool operator!=(List_iterator const &it) const;
        int  operator*() const;

    private:
        Element* pos{};
    };

    List_iterator begin() const;
    List_iterator end() const;
};
#endif
