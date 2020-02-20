#include "Circuit.h"

using namespace std;

void Circuit::insert(Component* input)
{
    net.push_back(input);
}

