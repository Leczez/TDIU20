// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <iostream>
using namespace std;


Time::Time(int h, int m, int s):
hour{h}, minute{m}, second{s}
{
        if (check_for_invalid_input(h,m,s)/*h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0*/)
        {
            throw_exception("invalid_input");
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
              throw_exception("invalid_input");
            }
        }
        else
        {
            throw_exception("invalid_format");
        }

}


bool Time::check_for_invalid_input(int h, int m, int s)
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

void Time::throw_exception(std::string message)
{
    Time(); //ska konstruktorn inte bara avsluta utan att skapa ett objekt?
    throw std::invalid_argument{message};
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