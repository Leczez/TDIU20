#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <array>
#include <sstream>
class Date
{
public:
    Date(std::string const &input);
    void print(std::ostream& os) const;
    void tomorrow();
private:
    bool is_leap_year(int year) const;
    int days_in_month(int year, int month) const;
    void format_into_ostream(int n, std::ostream& os) const;
    int year{};
    int month{};
    int day{};
};




#endif
