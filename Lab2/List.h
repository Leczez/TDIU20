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

    //friend class List_iterator;
    class List_iterator// Användaren ska kunna deklarera objekt av denna typ och kunna: !=, ++ och =
    {
    public:
        friend class List; // Nu bör List komma åt allt i private hos List_iterator
        class Element;
        List_iterator();

        List_iterator& operator=(List_iterator const &it);

    private:
        List_iterator(Element* ptr); //HJÄLPFUNKTION
        Element* pos{};
    };
    List_iterator begin(); //t.ex. i Mainprogrammet: List_iterator it = lista.begin();
    List_iterator end();


private:
    class Element
    {
    public:
        //friend class List_iterator;// behövs ej då iteratorklassen automatiskt har tillgång hit då den är nästlad.
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
};
