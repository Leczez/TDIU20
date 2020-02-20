#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "Component.h"

class Circuit
{
public:
    void simulate(int const& iterations, int const& rows, double const& time_step);
    void insert(Component* input); // ska insert:a komponenter.
private:
    std::vector<Component*> net{};
};




#endif
