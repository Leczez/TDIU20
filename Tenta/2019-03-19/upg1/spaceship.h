#pragma once
#include <string>
#include <vector>
#include <iostream>

class Crew
{
public:
    Crew(std::string const& n, std::string const& r): name{n}, rank{r} {}
    std::string get_name_and_rank() const;
private:
    std::string name;
    std::string rank;
};

class Ship
{
public:
    Ship(std::string const& n, int l): name{n}, length{l}, crewmembers{} {}
    void print(std::ostream & os) const;
    void add_crew_member(Crew const& c);

private:
    std::string name;
    int length;
    std::vector<Crew> crewmembers;


};
