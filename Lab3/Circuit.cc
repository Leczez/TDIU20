#include "Circuit.h"
#include <iostream>
#include <iomanip>


using namespace std;

Circuit::~Circuit()
{
    for(Connection* i : nodes)
    {
        delete i;
    }
    for(Component* i : net)
    {
        delete i;
    }

}


Connection& Circuit::get_node(std::string const& node) const
{
    Connection* A{};
    for(Connection* i : nodes)
    {
        if(i->get_name() == node)
        {
            A = i;
        }
    }
    if(A == nullptr)
    {
        throw Circuit_Error{"Node doesn't exist"};
    }
    return *A;
}

void Circuit::insert(Component* input)
{
    net.push_back(input);
}

void Circuit::create_node(std::string const& name)
{
    for(Connection* i : nodes) 
    {
        if(i->get_name() == name)
        {
            throw Circuit_Error{"Node already exists"};
        }

    }
    nodes.push_back(new Connection{name});
}

void Circuit::insert_resistor(std::string name, double value, std::string node1, std::string node2)
{
    insert(new Resistor{name, value, get_node(node1), get_node(node2)});
}

void Circuit::insert_capacitor(std::string name, double value, std::string node1, std::string node2)
{
    insert(new Capacitor{name, value, get_node(node1), get_node(node2)});
}

void Circuit::insert_battery(std::string name, double value, std::string node1, std::string node2)
{
    insert(new Battery{name, value, get_node(node1), get_node(node2)});
}



void Circuit::simulate(int const& iterations, int const& rows, double const& time_step)
{
    int width{14};
    int precision{2};

    for(Component* const e : net)
    {
        cout <<  setw(width) << e->get_name();
    }
    cout << endl;

     for(Component* const e : net)
    {
        cout <<  setw(width/2) << "Volt" << setw(width/2) << "Curr";
    }
    cout << endl;

    for(int i{}; i < rows; i++)
    {
        for(int i{}; i < iterations/rows;i++)
        {
            for(Component* const e : net)
            {
                e->tick(time_step);
            }
        }

        for(Component* const e : net)
        {
            cout << setw(width/2) << setprecision(precision) << fixed << e->get_voltage() << setw(width/2) << setprecision(precision)<< e->get_current();
        }
        cout << endl;
    }

}
