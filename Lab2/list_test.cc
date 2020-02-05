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

#if 0
#endif
