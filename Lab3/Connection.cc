#include "Connection.h"



void Connection::set_voltage(double const& input)
{
    voltage = input;
}

double Connection::get_voltage() const
{
    return voltage;
}