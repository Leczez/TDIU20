#include "Circuit.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Circuit::insert(Component* input)
{
    net.push_back(input);
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
