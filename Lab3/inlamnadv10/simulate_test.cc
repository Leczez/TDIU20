#include <sstream>
#include <utility>
#include "catch.hpp"
#include "Circuit.h"




//This is only meant to check our exceptionshandling

TEST_CASE("Trying to create duplicate")
{
    Circuit c{};
    c.create_node("p");
    CHECK_THROWS(c.create_node("p"));

}
TEST_CASE("Trying to create component with non-existing node")
{

    Circuit c{};
    c.create_node("p");
    CHECK_THROWS(c.insert_resistor("R1", 10,"p", "n"));
}



#if 0





#endif
