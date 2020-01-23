// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h
#include "Time.h"
#include <stdexcept>
#include <iostream>
//using namespace std;


Time::Time(int h, int m, int s):
hour{h}, minute{m}, second{s}
{
    try
    {
        if (h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0)
        {
            throw std::invalid_argument{"invalid_input"};
            //Time();
        }
    }
    catch(std::invalid_argument)
    {
        std::cerr << "INVALID INPUT!" << std::endl;
    }
}

Time::Time(std::string t)
{
    try
    {
        if (t.size() == 8 && t[2] == ':' && t[5] == ':')
        {
            int temp_hour = stoi(t.substr(0,1));
            int temp_minute = stoi(t.substr(3,4));
            int temp_second = stoi(t.substr(6,7));
            Time(temp_hour,temp_minute,temp_second);
        }
        else
        {
            throw std::invalid_argument{"invalid_format"};
            Time();
        }
    }
    catch(std::invalid_argument)
    {
        std::cerr << "INVALID FORMAT!" << std::endl;
    }

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
