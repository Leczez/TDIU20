#include "Circuit.h"

using namespace std;


int main()
{
    int iterations{10};
    int rows{10};
    double time_step{1};
    double battery_voltage{24};

    Circuit c{};
    Connection p{};
    Connection n{};
    Connection Q1{};
    Connection Q2{};
    c.insert(new Battery{"Bat", battery_voltage, p, n});
    c.insert(new Resistor{"R1", 6, p, Q1});
    c.insert(new Resistor{"R2", 4, Q1, Q2});
    c.insert(new Resistor{"R3", 8, Q2, n});
    c.insert(new Resistor{"R4", 12, Q1, n});
    c.simulate(iterations, rows, time_step);
    return 0;
}