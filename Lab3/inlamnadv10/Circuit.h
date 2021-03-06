#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "Component.h"
//#include <exception>
#include <stdexcept>
#include <iostream>

class Circuit
{
public:
    ~Circuit();

    void simulate(int const& iterations, int const& rows, double const& time_step);
    
    void create_node(std::string const& name);
    void insert_resistor(std::string name, double value, std::string node1, std::string node2);
    void insert_capacitor(std::string name, double value, std::string node1, std::string node2);
    void insert_battery(std::string name, double value, std::string node1, std::string node2);
private:
    Connection& get_node(std::string const& node) const;
    void insert(Component* input); // ska insert:a komponenter.
    std::vector<Component*> net{};
    std::vector<Connection*> nodes{};
};

class Circuit_Error : std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;

private:
};


#endif
