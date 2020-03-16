#include "date.h"

Date::Date(std::string const &input)
{
    std::stringstream ss{input};
    char garbage{};
    ss >> year >> garbage >> month >> garbage >> day;

    if ( month < 1 || month > 12 )
    {
      throw std::domain_error{"Month " + std::to_string(month) + " doesn't exist!"};
    }

    if (  day < 1 || day > days_in_month( year, month ) )
    {
      throw std::domain_error{"Day " + std::to_string(day) + " invalid"};
    }

}
void Date::tomorrow()
{
        if( day == days_in_month(year, month) )
        {
            day = 1;
            if( month == 12)
            {
                month = 1;
                year++;
            }
            else
            {
                month++;
            }
        }
        else
        {
            day++;
        }
}

bool Date::is_leap_year(int year) const
{
    if ( year % 400 == 0 )
      return true;
    if ( year % 100 == 0 )
      return false;
    return year % 4 == 0;
}

int Date::days_in_month(int year, int month) const
{
    static constexpr const std::array<int, 13> days
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12)
      return 0;

    if ( month == 2 && is_leap_year( year ) )
      return 29;

    return days.at(month);
}
void Date::print(std::ostream& os) const
{
    format_into_ostream(year, os);
    os << "-";
    format_into_ostream(month, os);
    os << "-";
    format_into_ostream(day, os);
    os << std::endl;
}
void Date::format_into_ostream(int n, std::ostream& os) const
{
    if(n < 10)
    {
        os << 0;
    }
    os << n;
}
