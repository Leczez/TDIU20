#include "Component.h"
#include <iostream>

using namespace std;

//Component
Component::Component(std::string n, Connection &first, Connection &last):
name{n}, A{first}, B{last}
{}


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
Resistor::Resistor(std::string n, double data, Connection &first, Connection &last):
Component(n, first, last), resistance{data}
{}

double Resistor::get_current() const
{
    return get_voltage()/resistance;
}

void Resistor::tick(double const& time_period)
{
    double change_in_potential = ((A.get_potential() - B.get_potential())/resistance) * time_period;
    A.set_potential( A.get_potential() - change_in_potential);
    B.set_potential( B.get_potential() + change_in_potential);
}


//Capacitor
Capacitor::Capacitor(std::string n, double data, Connection &first, Connection &last):
Component(n, first, last), capacitance{data}, charge{0}
{}

double Capacitor::get_current() const
{
    return capacitance*(get_voltage()-charge);
}

void Capacitor::tick(double const& time_period)
{
    if(A.get_potential() >= B.get_potential())
    {
        double difference = A.get_potential() - B.get_potential();
        difference = (difference-charge) * capacitance * time_period;
        A.set_potential(A.get_potential() - difference);
        B.set_potential(B.get_potential() + difference);
        charge += difference;
    }
    else
    {
        double difference = B.get_potential() - A.get_potential();
        difference = (difference-charge) * capacitance* time_period;
        A.set_potential(A.get_potential() + difference);
        B.set_potential(B.get_potential() - difference);
        charge += difference;
    }
}


//Battery
Battery::Battery(std::string n, double data, Connection &first, Connection &last):
Component(n, first, last), voltage{data}
{}

double Battery::get_voltage() const
{
    return voltage;
}


double Battery::get_current() const
{
    return 0;
}

void Battery::tick(double const& time_period)
{
    double dummy = time_period;
    dummy = dummy;
    A.set_potential(voltage);
    B.set_potential(0);
}
