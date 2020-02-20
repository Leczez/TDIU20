#include "Component.h"
#include <iostream>

using namespace std;

//Component
Component::Component(std::string n, double data, Connection first, Connection last):
name{n}, value{data}, A{first}, B{last}{}

double Component::get_voltage() const
{
    return (A.get_voltage() - B.get_voltage());    
}

std::string Component::get_name() const
{
    return name;
}

//Resistor
/*
double Resistor::get_voltage() const
{
    return A.get_voltage() - B.get_voltage();    
}
*/

double Resistor::get_current() const
{
    return get_voltage()/value;
}

void Resistor::tick(double const& time_period)
{
    double change_in_potential = ((A.get_voltage() - B.get_voltage())/value) * time_period;
    A.set_voltage( A.get_voltage()-change_in_potential);
    B.set_voltage( B.get_voltage()+change_in_potential);
}


//Capacitor
double Capacitor::get_current() const
{
    //tick kommer uppdater gammla Charge:n
    return value*(get_voltage()-charge);
}

void Capacitor::tick(double const& time_period)
{

}


//Battery
double Battery::get_voltage() const
{
    return value;
}


double Battery::get_current() const
{
    return value - value;
}

void Battery::tick(double const& time_period)
{
    A.set_voltage(value);
    B.set_voltage(0);
}
