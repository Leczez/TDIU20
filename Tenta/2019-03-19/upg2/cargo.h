#pragma once
#include <string>
#include <iostream>


class Cargo
{
public:
    Cargo(std::string const& n, int v): name{n}, value{v} {}
    friend std::ostream & operator<<(std::ostream & os, Cargo const& c);
    Cargo operator+(Cargo const& rhs) const;
private:
    std::string name;
    int value;
};
