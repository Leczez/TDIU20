// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <iostream>
using namespace std;


Time::Time(int h, int m, int s):
hour{h}, minute{m}, second{s}
{
    //try
    //{
        if (check_for_invalid_input(h,m,s)/*h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0*/)
        {
            //Time();
            //throw std::invalid_argument{"invalid_input"};
            throw_exception("invalid_input");
        }
      //}
    /*catch(std::invalid_argument)
    {
        std::cerr << "INVALID INPUT!" << std::endl;
    }
    */
}

Time::Time(std::string t)
{
    //try
    //{
        if (t.size() == 8 && t[2] == ':' && t[5] == ':')
        {
            hour = stoi(t.substr(0,2));
            minute = stoi(t.substr(3,2));
            second = stoi(t.substr(6,2));

            if (check_for_invalid_input(hour,minute,second))
            {
              //Time();
              //throw std::invalid_argument{"invalid_input"};
              throw_exception("invalid_input");
            }
        }
        else
        {
            //Time();
            //throw std::invalid_argument{"invalid_format"};
            throw_exception("invalid_format");
        }
    //}
    /*
    catch(std::invalid_argument)
    {
        std::cerr << "INVALID FORMAT!" << std::endl;
    }
    */
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
    Time();
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
