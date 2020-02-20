#include "Component.h"

//Component
Component::Component(std::string n, double data, Connection& first, Connection& last):
name{n}, value{data}, A{first}, B{last}{}

double Component::get_voltage() const
{
    return (A.get_voltage() - B.get_voltage());    
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
    return 0;
}

void Battery::tick(double const& time_period)
{

}
