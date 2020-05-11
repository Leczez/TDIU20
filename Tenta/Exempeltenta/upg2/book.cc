#include "book.h"

std::istream& operator>>(std::istream& is, Book& b)
{
    std::string allt{};
    getline(is, allt);

    std::stringstream ss{allt};
    std::string title{};
    std::string author{};
    int pages{};
    getline(ss, title, ';');
    ss.ignore(); //IGNORERAR BLANKSTEGET SOM MAN TYDLIGEN MÅSTE MATA IN
    getline(ss, author, ';');
    ss.ignore();
    ss >> pages;
    b = Book(author,title,pages);
    return is;
}

std::ostream& operator<<(std::ostream& os, Book& b)
{
    os << b.author <<"; "<< b.title <<"; "<< b.pages << std::endl;
    return os;
}
