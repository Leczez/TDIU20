#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "Component.h"

class Circuit
{
public:
    void simulate();
    //void insert(Component* input); // ska insert:a komponenter.
    std::vector<Component*> net{}; // ska bli private
private:

};




#endif
