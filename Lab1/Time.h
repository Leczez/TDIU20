// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>

class Time
{
public:
    Time() = default;
    Time(int const h, int const m, int const s);
    Time(std::string const &t);

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    bool is_am() const;
    std::string to_string( const bool = false) const;
    operator std::string() const;

    Time operator+(int const n) const;
    Time operator++(int);
    Time& operator++();
    Time operator-(int const n) const;
    Time operator--(int);
    Time& operator--();

    bool operator==(Time const &t) const;
    bool operator!=(Time const &t) const;
    bool operator<(Time const &t) const;
    bool operator>(Time const &t) const;
    bool operator<=(Time const &t) const;
    bool operator>=(Time const &t) const;

    friend std::ostream& operator<<(std::ostream &os, Time const &t);
    friend std::istream& operator>>(std::istream &is, Time &t);
private:
    int hour{};
    int minute{};
    int second{};

    bool check_for_invalid_input(int const h, int const m, int const s) const;
    void format_into_ostream (int const n, std::ostream &os) const;
};

#endif
