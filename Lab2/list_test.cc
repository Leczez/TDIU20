#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "List.h"

using namespace std;

// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("Default constructor")
{
    List l{};
}

TEST_CASE("Single Insert")
{
    List list{};
    list.insert(10);
}

TEST_CASE("Remove function")
{
    stringstream ss{};

    List list{};
    list.insert(10);
    list.insert(11);
    list.insert(12);
    list.insert(13);

    list.remove(1);
    ss << list;
    CHECK(ss.str() == "10 12 13");

    SECTION("Exception")
    {
        List list{};
        list.insert(10);
        list.insert(11);
        list.insert(12);
        list.insert(13);
        CHECK_THROWS(list.remove(6));
    }

}
#if 0

#endif
