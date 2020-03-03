#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "Component.h"

class Circuit
{
public:
    void simulate(int const& iterations, int const& rows, double const& time_step);
    
    void create_node(std::string const& name);
    void insert_resistor(std::string name, double value, std::string node1, std::string node2);
    void insert_capacitor(std::string name, double value, std::string node1, std::string node2);
    void insert_battery(std::string name, double value, std::string node1, std::string node2);
private:
    void insert(Component* input, std::string node1, std::string node2); // ska insert:a komponenter.
    std::vector<Component*> net{};
    std::vector<Connection*> nodes{};
};




#endif
