#include "integer.h"


Integer::Integer() : unsigned_value{0}, sign{true}
{}

Integer::Integer(int const input) : unsigned_value{0}, sign{true}
{
    if( input < 0)
    {
        unsigned_value = (input*(-1));
        sign = false;
    }
    else
    {
        unsigned_value = input;
        sign = true;
    }
}
Integer::operator int () const
{
    if(unsigned_value > std::numeric_limits<int>::max())
    throw std::range_error{"OJ"};
    if(sign)
    return unsigned_value;
    else
    return (unsigned_value*-(1));
}
bool Integer::operator==(int const rhs) const
{
    if(sign)
    {
        return static_cast<int>(unsigned_value) == rhs;
    }
    else
    {
        return static_cast<int>( (unsigned_value*(-1)) ) == rhs;
    }
}


bool Integer::operator==(Integer const rhs) const
{

    return (sign == rhs.sign && unsigned_value == rhs.unsigned_value);
}

bool Integer::operator<(Integer const &rhs) const
{
    if(sign && rhs.sign)
    {
        return unsigned_value < rhs.unsigned_value;
    }
    else if( !sign && !rhs.sign)
    {
        return unsigned_value > rhs.unsigned_value;
    }
    else if( sign && !rhs.sign)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Integer& Integer::operator++()
{
    if(sign)
    {
        ++unsigned_value;
    }
    else if(!sign)
    {
        --unsigned_value;
    }

    if(!sign && unsigned_value == 0)
    {
        sign = true;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, Integer const &rhs)
{
    if(!rhs.sign)
    {
        os << '-';
    }
    os << rhs.unsigned_value;
    return os;
}
