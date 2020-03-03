#include "Circuit.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Circuit::insert(Component* input, std::string node1, std::string node2)
{
    Connection* node_1;
    Connection* node_2;
    int counter{};
    while(counter < nodes.size())
    {
        if(*(nodes[counter]).get_name() == node1)
        {
            node_1 = net[counter];
        }
        if(*(nodes[counter]).get_name() == node2)
        {
            node_2 = net[counter];
        }
    }
    net.push_back(input);
}

void Circuit::create_node(std::string const& name)
{
    nodes.push_back(new Connection{name});
}

void Circuit::insert_resistor(std::string name, double value, std::string node1, std::string node2)
{
    
    //insert(new Resistor{name,value,})
}

void Circuit::insert_capacitor(std::string name, double value, std::string node1, std::string node2)
{

}

void Circuit::insert_battery(std::string name, double value, std::string node1, std::string node2)
{

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
