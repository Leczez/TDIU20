#include "Circuit.h"
#include <string>
using namespace std;

//TODO: Vid felaktig inskrift ska ett instruktivt felmeddelande
//skrivas ut. Tänk er att en användare som inte har någon koll på hur
//ert program fungerar ska kunna skriva in rätt argument efter felmeddelandet.
const std::string ERRORMESSAGE = "The arguments expected are:\n"
"Number of iterations, in positive integers\n"
"Number of lines to print, in positive integers\n"
"Time interval each iteration simulates, in positive seconds\n"
"Battery voltage, in positive volts\n"
"Example: 200000 10 0.01 24\n";

int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        throw invalid_argument{"WRONG NUMBER OF ARGUMENTS!\n" + ERRORMESSAGE};

    }
    int iterations{};
    int rows{};
    double time_step{};
    double battery_voltage{};

    try
    {
        if(stoi(argv[1]) < 0 || stoi(argv[2]) < 0 || stoi(argv[3]) < 0 || stoi(argv[4]) < 0)
        {
            throw logic_error{"NEGATIVE NUMBERS ARE NOT ALLOWED!\n" + ERRORMESSAGE};
        }
        iterations = std::stoi(argv[1]);
        rows = std::stoi(argv[2]);
        time_step = std::stod(argv[3]);
        battery_voltage = std::stod(argv[4]);
    }
    catch(invalid_argument e)
    {
        throw invalid_argument{"INVALID INPUT!\n" + ERRORMESSAGE};
    }

    Circuit c{};
    c.create_node("p");
    c.create_node("n");
    c.create_node("l");
    c.create_node("r");

    c.insert_battery("Bat", battery_voltage, "p", "n");
    c.insert_resistor("R1", 6, "p", "l");
    c.insert_resistor("R2", 4, "l", "r");
    c.insert_resistor("R3", 8, "r", "n");
    c.insert_resistor("R4", 12, "l", "n");
    c.simulate(iterations, rows, time_step);


    Circuit c2{};
    c2.create_node("p");
    c2.create_node("n");
    c2.create_node("l");
    c2.create_node("r");

    c2.insert_battery("Bat", battery_voltage, "p", "n");
    c2.insert_resistor("R1", 150, "p", "l");
    c2.insert_resistor("R2", 50, "p", "r");
    c2.insert_resistor("R3", 100, "l", "r");
    c2.insert_resistor("R4", 300, "l", "n");
    c2.insert_resistor("R5", 250, "r", "n");
    c2.simulate(iterations, rows, time_step);

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
    c3.simulate(iterations, rows, time_step);

    return 0;
}
