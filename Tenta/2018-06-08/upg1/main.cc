#include "date.h"

int main()
{
    std::string inmatning{};
    std::cout << "Enter a date: ";
    std::cin >> inmatning;
    Date datum{inmatning};

    datum.print(std::cout);
    std::cout << "10000 days later: ";
    for(int i = 0; i < 10000; i++)
    {
        datum.tomorrow();
    }
    datum.print(std::cout);


    return 0;
}
