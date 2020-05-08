#ifndef EBOOK_H
#define EBOOK_H
#include <string>
#include <iostream>
#include <sstream>
class Ebook
{
public:
    Ebook(std::string const& s, int const w  = 80, int const r = 40);
    std::string next_page();
private:
    std::string const &content;
    std::string::size_type start_of_page;
    int width; //Tecken per rad
    int rows;  //Rader per sida

};


#endif
