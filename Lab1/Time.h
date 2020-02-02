// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Time
{
public:
    Time() = default;
    Time(int h, int m, int s);
    Time(std::string t);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    
    void set_hour(int n);
    void set_minute(int n);
    void set_second(int n);

    bool is_am() const;
    std::string to_string( bool = false) const;
    Time operator+(int const N);
    Time operator++(int);
    Time& operator++();
    Time operator-(int const N);
    Time operator--(int);
    Time& operator--();
    operator std::string() const;
    bool operator==(Time const& t) const;
    bool operator!=(Time const& t) const;
    bool operator<(Time const& t) const;
    bool operator>(Time const& t) const;
    bool operator<=(Time const& t) const;
    bool operator>=(Time const& t) const;
    bool check_for_invalid_input(int h, int m, int s) const;
private:
    int hour{};
    int minute{};
    int second{};
    //bool check_for_invalid_input(int h, int m, int s) const;
    void format_into_ostream (int n, std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, Time const& t);
std::istream& operator>>(std::istream& is, Time & t);
#endif
