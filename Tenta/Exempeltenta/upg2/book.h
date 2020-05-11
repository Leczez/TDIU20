#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <sstream>

class Book
{
public:
    Book(const std::string& a, const std::string& t, const int p):author{a},title{t}, pages{p}
    {}
    Book() = default;
    friend std::istream& operator>>(std::istream& is, Book& b);
    friend std::ostream& operator<<(std::ostream& os, Book& b);
private:
    std::string author{};
    std::string title{};
    int pages{};

};
#endif
