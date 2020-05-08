#ifndef REPORT_H
#define REPORT_H
#include <string>
#include <vector>
#include <iostream>

class Chapter
{
private:
    std::string Titel, Inledning;
    std::vector<Chapter> WTF;
public:
    std::string& text() const {return}

};



class Report
{
private:
    std::string Title;


public:
    Report(std::string s): Title{s}, authors{} {}
    std::vector<std::string> authors;
    Chapter& new_chapter(std::string const &chaptername);


};










#endif
