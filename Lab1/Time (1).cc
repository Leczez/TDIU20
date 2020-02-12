// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;


Time::Time(int const h, int const m, int const s):
hour{h}, minute{m}, second{s}
{
    if(check_for_invalid_input(h, m, s))
    {
        throw std::invalid_argument{"invalid_input"};
    }
}


Time::Time(std::string const &t)
{
    if(t.size() == 8 && t[2] == ':' && t[5] == ':')
    {
        hour   = stoi(t.substr(0, 2));
        minute = stoi(t.substr(3, 2));
        second = stoi(t.substr(6, 2));

        if(check_for_invalid_input(hour, minute, second))
        {
            throw std::invalid_argument{"invalid_input"};
        }
    }
    else
    {
        throw std::invalid_argument{"invalid_format"};
    }
}


bool Time::check_for_invalid_input(int const h, int const m, int const s) const
{
    if(h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Time::is_am() const
{
    if(hour < 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}


string Time::to_string(const bool am_pm_format) const
{
    ostringstream ss{};
    if(am_pm_format && hour > 12)
    {
        format_into_ostream((hour - 12), ss);
    }
    else if(am_pm_format && hour < 1)
    {
        format_into_ostream((hour + 12), ss);
    }
    else
    {
        format_into_ostream(hour, ss);
    }

    ss << ':';
    format_into_ostream(minute, ss);
    ss << ':';
    format_into_ostream(second, ss);

    if(am_pm_format )
    {
        if(is_am())
        {
            ss << " am";
        }
        else
        {
            ss << " pm";
        }
    }
    return ss.str();
}


void Time::format_into_ostream (int const n, ostream &os) const
{
    if( n < 10)
    {
        os << 0;
    }
    os << n;
}


Time Time::operator+(int const n)
{
    Time temp{hour, minute, second};
    if(n < 0)
    {
        temp = temp -(-n);
    }
    else
    {
	// Kommentar: Detta är en mycket seg lösning. Det är godkänt i
	// detta fall men kan vara bra att tänka på i framtiden.
	for(int i{}; i < n; i++)
        {
          temp++;
        }
    }
    return temp;
}


Time Time::operator++(int)
{
    Time t{*this};
    ++(*this);
    return t;
}


Time& Time::operator++()
{
    second++;
    if(second > 59)
    {
        second = 0;
        minute++;
        if(minute > 59)
        {
            minute = 0;
            hour++;
            if(hour > 23)
            {
                hour = 0;
              }
        }
    }
    return *this;
}


Time Time::operator-(int const n)
{
    Time temp{hour, minute, second};

    if(n < 0)
    {
        temp = temp + (-n);
    }
    else
    {
        for(int i{}; i < n; i++)
        {
              temp--;
        }
    }
    return temp;
}


Time Time::operator--(int)
{
    Time t{*this};
    --(*this);
    return t;
}


Time& Time::operator--()
{
    second--;
    if(second < 0)
    {
        second = 59;
        minute--;
        if(minute < 0)
        {
            minute = 59;
            hour--;
            if(hour < 0)
            {
                hour = 23;
              }
        }
    }
    return *this;
}

// TODO: Implementera endast 2 helst 1 av jämförelseoperatorerna och
// återanvänd den/dem i implementationen av de andra.
bool Time::operator==(Time const &t) const
{
    if(hour == t.hour && minute == t.minute && second == t.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Time::operator!=(Time const &t) const
{
    if(hour != t.hour || minute != t.minute || second != t.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Time::operator<(Time const &t) const
{
    if(hour < t.hour)
    {
        return true;
    }
    else
    {
        if(hour == t.hour && minute < t.minute)
        {
            return true;
        }
        else
        {
            if(hour == t.hour && minute == t.minute && second < t.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


bool Time::operator>(Time const &t) const
{
    if(hour > t.hour)
    {
        return true;
    }
    else
    {
        if(hour == t.hour && minute > t.minute)
        {
            return true;
        }
        else
        {
            if(hour == t.hour && minute == t.minute && second > t.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


bool Time::operator<=(Time const &t) const
{
    Time temp{*this};
    if(temp < t || temp == t)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Time::operator>=(Time const &t) const
{
    Time temp{*this};
    if(temp > t || temp == t)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Time::operator string() const
{
    return to_string();
}

int Time::get_hour() const
{
    return hour;
}

int Time::get_minute() const
{
    return minute;
}

int Time::get_second() const
{
    return second;
}

// TODO: Ni måste kolla så det blir ett rimligt tal även med set. Som
// det ser ut nu så kan man skapa felaktiga tider.
void Time::set_hour(int const n)
{
    hour = n;
}

void Time::set_minute(int const n)
{
    minute = n;
}

void Time::set_second(int const n)
{
   second = n;
}


ostream& operator<<(ostream &os, Time const &t)
{
    os << t.to_string();
    return os;
}


istream& operator>>(istream &is, Time &t)
{
    int h {};
    int m {};
    int s {};
    char c {};
    is >> h >> c >> m >> c >> s;

    if(t.check_for_invalid_input(h, m, s))
    {
        is.setstate(std::ios_base::failbit);
    }
    else
    {
        t.hour   = h;
        t.minute = m;
        t.second = s;
    }
    return is;
}
