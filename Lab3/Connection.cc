#include "Connection.h"
#include <iostream>

using namespace std;



void Connection::set_potential(double const& input)
{
    potential = input;
}

double Connection::get_potential() const
{
    return potential;
}
