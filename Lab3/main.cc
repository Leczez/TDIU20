#include "Circuit.h"
#include <sstream>

using namespace std;


int main(int argc, char* argv[])
{
    //cout << argc << endl;
    if(argc != 5)
    {
        throw invalid_argument{"Wrong number of arguments"};
      //  cout << argc << endl;

    }
    int iterations{};
    int rows{};
    double time_step{};
    double battery_voltage{};

    try
    {   
        if(stoi(argv[1]) < 0 || stoi(argv[2]) < 0 || stoi(argv[3]) < 0 || stoi(argv[4]) < 0)
        {
            throw logic_error{"Negative input is not allowed"};
        }
        iterations = std::stoi(argv[1]);
        rows = std::stoi(argv[2]);
        time_step = std::stod(argv[3]);
        battery_voltage = std::stod(argv[4]);
    }
    catch(invalid_argument e)
    {
        throw invalid_argument{"Invalid input!"};
    }
    

    stringstream ss{};

    Circuit c3{};
    c3.create_node("p");
    c3.create_node("n");
    c3.create_node("l");
    c3.create_node("r");
    c3.insert_battery("Bat", battery_voltage, "p", "n");
    c3.insert_resistor("R1", 150, "p", "l");
    c3.insert_resistor("R2", 50, "p", "r");
    c3.insert_capacitor("C3", 1, "l", "r");
    c3.insert_resistor("R4", 300, "l", "n");
    c3.insert_capacitor("C5", 0.75, "r", "n");
    c3.simulate(iterations, rows, time_step, ss);

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
/*
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
*/
/*
    Circuit c0{}; //HITTAPÅTEST
    Connection p{};
    Connection n{};
    Connection a{};
    c0.insert(new Battery{"Bat", battery_voltage, p, n});
    c0.insert(new Resistor{"R1", 10, p, a});
    c0.insert(new Capacitor{"C1", 0.75, a, n});
    c0.simulate(iterations, rows, time_step);
  */
    return 0;
}
