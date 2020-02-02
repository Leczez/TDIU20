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
    if(am_pm_format && hour > 12)
    {
        format_into_ostream(hour-12, ss);
    }
    else if(am_pm_format && hour < 1)
    {
        format_into_ostream(hour+12, ss);
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
    if(N < 0)
    {
        temp = temp -(-N);
    }
    else
    {
        for(int i{}; i < N;i++)
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

Time Time::operator-(int N)
{
    Time temp{hour,minute,second};

    if(N < 0)
    {
        temp = temp + (-N);
    }
    else
    {
        for(int i{}; i < N;i++)
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

bool Time::operator==(Time const& t) const
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

bool Time::operator!=(Time const& t) const
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

bool Time::operator<(Time const& t) const
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

bool Time::operator>(Time const& t) const
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

bool Time::operator<=(Time const& t) const
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

bool Time::operator>=(Time const& t) const
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

ostream& operator<<(ostream& os, Time const& t)
{
    os << t.to_string();
    return os;
}
istream& operator>>(istream& is, Time & t)
{
    int temp_h {};
    int temp_m {};
    int temp_s {};
    char c {};
    is >> temp_h >> c >> temp_m >> c >> temp_s;
    Time temp_t(temp_h,temp_m,temp_s);

    if(t.check_for_invalid_input(temp_h, temp_m, temp_s))
    {
        is.setstate(std::ios_base::failbit);
    }
    else
    {
        t = temp_t;
    }
    return is;
}
