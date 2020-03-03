#include "Connection.h"
#include <iostream>

using namespace std;

Connection::Connection(std::string input):name{input}
{}

void Connection::set_potential(double const& input)
{
    potential = input;
}

double Connection::get_potential() const
{
    return potential;
}



std::string Connection::get_name() const
{
    return name;
}
