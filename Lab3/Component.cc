#include "Component.h"
#include <iostream>

using namespace std;

//Component
Component::Component(std::string n, double data, Connection &first, Connection &last):
name{n}, value{data}, A{first}, B{last}{}

double Component::get_voltage() const
{
    double voltage{};
    if(A.get_potential() >= B.get_potential())
    {
        voltage = A.get_potential() - B.get_potential();
    }
    else
    {
        voltage = B.get_potential() - A.get_potential();
    }
    return voltage;
}

std::string Component::get_name() const
{
    return name;
}

//Resistor
double Resistor::get_current() const
{
    return get_voltage()/value;
}

void Resistor::tick(double const& time_period)
{
    double change_in_potential = ((A.get_potential() - B.get_potential())/value) * time_period;
    A.set_potential( A.get_potential() - change_in_potential);
    B.set_potential( B.get_potential() + change_in_potential);
}


//Capacitor
double Capacitor::get_current() const
{
    //tick kommer uppdater gammla Charge:n
    return value*(get_voltage()-charge);
}

void Capacitor::tick(double const& time_period)
{
    double difference{};
    if(A.get_potential() >= B.get_potential())
    {
        difference = A.get_potential() - B.get_potential();
        charge += (difference-charge) * value * time_period;
        A.set_potential( A.get_potential() - charge);
        B.set_potential( B.get_potential() + charge);
    }
    else
    {
        difference = B.get_potential() - A.get_potential();
        charge += (difference-charge) * value * time_period;
        A.set_potential( A.get_potential() + charge);
        B.set_potential( B.get_potential() - charge);
    }
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
    A.set_potential(value);
    B.set_potential(0);
}
