// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;


Time::Time(int h, int m, int s):
hour{h}, minute{m}, second{s}
{
    if (check_for_invalid_input(h,m,s))
    {
        throw std::invalid_argument{"invalid_input"};
    }
}


Time::Time(std::string t)
{
    if (t.size() == 8 && t[2] == ':' && t[5] == ':')
    {
        hour = stoi(t.substr(0,2));
        minute = stoi(t.substr(3,2));
        second = stoi(t.substr(6,2));

        if (check_for_invalid_input(hour,minute,second))
        {
            throw std::invalid_argument{"invalid_input"};
        }
    }
    else
    {
        throw std::invalid_argument{"invalid_format"};
    }
}


bool Time::check_for_invalid_input(int h, int m, int s) const
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
    if (hour < 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}


string Time::to_string(bool am_pm_format ) const
{
    stringstream ss{};
    if(am_pm_format && !is_am())
    {
        format_into_ostream(hour-12, ss);
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
        if(hour >= 12)
        {
            ss << " pm";
        }
        else
        {
            ss << " am";
        }
    }
    return ss.str();
}


void Time::format_into_ostream (int n, ostream& os) const
{
    if( n < 10)
    {
        os << 0 << n;
    }
    else
    {
        os << n;
    }
}

Time Time::operator+(int N)
{
    Time temp{hour,minute,second};
    for(int i{}; i < N;i++)
    {
      temp++;
      cout << "operator+ "<< temp.hour << " " << temp.minute << " " << temp.second << endl;
    }
    cout << "operator2+ "<< temp.hour << " " << temp.minute << " " << temp.second << endl;
    return temp;
}

void Time::operator++(int)
{
    //Time t{*this};
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
    cout << "operator++ "<< hour << " " << minute << " " << second << endl;
    //return t;
}
void Time::operator++()
{
    //Time t{*this};
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
    cout << "operator++ "<< hour << " " << minute << " " << second << endl;
    //return t;
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
