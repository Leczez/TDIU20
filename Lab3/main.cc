#include "Circuit.h"

using namespace std;


int main()
{
    int iterations{200000};
    int rows{10};
    double time_step{0.01};
    double battery_voltage{24};

    /*Circuit c{};
    Connection p{};
    Connection n{};
    Connection q1{};
    Connection q2{};
    c.insert(new Battery{"Bat", battery_voltage, p, n});
    //c.insert(new Resistor{"R1", 6, p, n});
    c.insert(new Resistor{"R1", 6, p, q1});
    c.insert(new Resistor{"R2", 4, q1, q2});
    c.insert(new Resistor{"R3", 8, q2, n});
    c.insert(new Resistor{"R4", 12, q1, n});
    c.simulate(iterations, rows, time_step);*/

    /*Circuit c2{};
    Connection p{};
    Connection n{};
    Connection l{};
    Connection r{};
    c2.insert(new Battery{"Bat", battery_voltage, p, n});
    c2.insert(new Resistor{"R1", 150, p, l});
    c2.insert(new Resistor{"R2", 50, p, r});
    c2.insert(new Resistor{"R3", 100, l, r});
    c2.insert(new Resistor{"R4", 300, l, n});
    c2.insert(new Resistor{"R5", 250, r, n});
    c2.simulate(iterations, rows, time_step);*/

    Circuit c3{};
    Connection p{};
    Connection n{};
    Connection l{};
    Connection r{};
    c3.insert(new Battery{"Bat", battery_voltage, p, n});
    c3.insert(new Resistor{"R1", 150, p, l});
    c3.insert(new Resistor{"R2", 50, p, r});
    c3.insert(new Capacitor{"C3", 1, l, r});
    c3.insert(new Resistor{"R4", 300, l, n});
    c3.insert(new Capacitor{"C5", 0.75, r, n});
    c3.simulate(iterations, rows, time_step);

    /*Circuit c0{}; //HITTAPÅTEST
    Connection p{};
    Connection n{};
    Connection a{};
    c0.insert(new Battery{"Bat", battery_voltage, p, n});
    c0.insert(new Resistor{"R1", 10, p, a});
    c0.insert(new Capacitor{"C1", 0.75, a, n});
    c0.simulate(iterations, rows, time_step);*/
    return 0;
}
