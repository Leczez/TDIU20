#include "cargo.h"

std::ostream & operator<<(std::ostream & os, Cargo const& c)
{
    return os << c.name << " " << c.value;
}

Cargo Cargo::operator+(Cargo const& rhs) const
{
    return Cargo(name+rhs.name, value+rhs.value);
}
