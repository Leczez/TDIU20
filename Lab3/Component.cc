#include "Component.h"

//Component
Component::Component(std::string n, double data, Connection& first, Connection& last):
name{n}, value{data}, A{first}, B{last}{}

//Resistor
double Resistor::get_voltage() const
{
    
}

double Resistor::get_current() const
{

}

void Resistor::tick(double const& time_period)
{

}


//Capacitor
double Capacitor::get_voltage() const
{

}

double Capacitor::get_current() const
{

}

void Capacitor::tick(double const& time_period)
{

}


//Battery
double Battery::get_voltage() const
{
    return voltage;
}

double Battery::get_current() const
{

}

void Battery::tick(double const& time_period)
{

}
