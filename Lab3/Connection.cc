#include "Connection.h"
#include <iostream>

using namespace std;



void Connection::set_voltage(double const& input)
{
    voltage = input;
    //cout << "voltage " << voltage << endl;
}

double Connection::get_voltage() const
{
    return voltage;
}