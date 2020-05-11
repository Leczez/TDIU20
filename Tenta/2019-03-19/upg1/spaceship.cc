#include "spaceship.h"


std::string Crew::get_name_and_rank() const
{
    return name + " - " + rank;
}

void Ship::print(std::ostream & os) const
{
    os << "name: " << name << "\nlength: " << length << "\ncrew:" << std::endl;

    for(Crew x: crewmembers)
    {
        os << x.get_name_and_rank() << std::endl;
    }
}

void Ship::add_crew_member(Crew const& c)
{
    crewmembers.push_back(c);
}
