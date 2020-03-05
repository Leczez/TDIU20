#include "Component.h"
#include <iostream>

using namespace std;

//Component

Component::Component(std::string n, double data, Connection &first, Connection &last):
name{n}, value{data}, A{first}, B{last}
{}

/*
Component::Component(std::string n, double data):name{n}, value {data}, A{dummynode}, B{dummynode}
{}
*/
void Component::set_nodes(Connection&  node1, Connection& node2)
{
    A = node1;
    B = node2;
}

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

    //voltage = A.get_potential() - B.get_potential();

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
    if(A.get_potential() >= B.get_potential())
    {
        double difference = A.get_potential() - B.get_potential();
        difference = (difference-charge) * value * time_period;
        A.set_potential(A.get_potential() - difference);
        B.set_potential(B.get_potential() + difference);
        charge += difference;
    }
    else
    {
        double difference = B.get_potential() - A.get_potential();
        difference = (difference-charge) * value * time_period;
        A.set_potential(A.get_potential() + difference);
        B.set_potential(B.get_potential() - difference);
        charge += difference;
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
    double dummy = time_period;
    dummy = dummy;
    A.set_potential(value);
    B.set_potential(0);
}
