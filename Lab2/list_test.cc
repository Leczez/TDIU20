#include <string>
#include <iostream>
#include <sstream>
#include <utility>
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

TEST_CASE("Multiple Inserts")
{
    List list{};
    list.insert(1);
    list.insert(3);
    list.insert(6);
    list.insert(-1);
    list.insert(10);
    list.insert(10);
    list.insert(0);

    stringstream ss{};
    ss << list;
    CHECK(ss.str() == "-1 0 1 3 6 10 10");
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

TEST_CASE("Initilizer constructor")
{
    stringstream ss{};

    List list{5,4,10};

    ss << list;
    CHECK(ss.str() == "4 5 10");

}

TEST_CASE("Listsize")
{
    stringstream ss{};

    List list{5,4,10};
    list.insert(1);
    CHECK(list.size() == 4);
    list.remove(0);
    CHECK(list.size() == 3);
    list.remove(0);
    CHECK(list.size() == 2);
    list.remove(0);
    CHECK(list.size() == 1);
    list.remove(0);
    CHECK(list.size() == 0);


}

TEST_CASE("Copy constructor")
{
    stringstream ss{};

    List list{5,4,10};
    List list2{list};
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty copy")
    {
        stringstream ss{};
        List list{};
        List list2{list};
        ss << list2;
        CHECK(ss.str() == "");
    }
    SECTION("Changes only the copy")
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2{list};
        list2.insert(10);
        list2.remove(0);
        list.remove(0);
        ss << list;
        ss2 << list2;
        CHECK(ss.str() == "3 5");
        CHECK(ss2.str() == "3 5 10");
    }
}

TEST_CASE("Copy operator")
{
    stringstream ss{};

    List list{5,4,10};
    List list2 = list;
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty copy")
    {
        stringstream ss{};
        List list{};
        List list2 = list;
        ss << list2;
        CHECK(ss.str() == "");
    }

    SECTION("Changes only the copy")
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2 = list;
        list2.insert(10);
        list2.remove(0);
        list.remove(0);
        ss << list;
        ss2 << list2;
        CHECK(ss.str() == "3 5");
        CHECK(ss2.str() == "3 5 10");
    }
}

TEST_CASE("Move constructor")
{
    stringstream ss{};

    List list{5,4,10};
    List list2{std::move(list)};
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty copy")
    {
        stringstream ss{};
        List list{};
        List list2{std::move(list)};
        ss << list2;
        CHECK(ss.str() == "");
    }
    SECTION("Extra Tests")
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2{std::move(list)};
        list2.insert(10);
        list2.remove(0);
        ss << list2;
        CHECK(ss.str() == "3 5 10");

    }
}

TEST_CASE("Move operator")
{
    stringstream ss{};

    List list{5,4,10};
    List list2 = std::move(list);
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty copy")
    {
        stringstream ss{};
        List list{};
        List list2 = std::move(list);
        ss << list2;
        CHECK(ss.str() == "");
    }
}

TEST_CASE("Index operator")
{
    List list{1,2,3,4,5};

    CHECK(list[1] == 2);

    CHECK(list[4] == 5);

    SECTION("Check for Index out of bounds!")
    {
        List list{1,2,3,4,5};
        CHECK_THROWS(list[7]);
    }
}

TEST_CASE("List_Iterator init")
{
    List::List_iterator{};
    //List list{1,2,3,4,5};
    //List_iterator = list.begin();

    //List::List_iterator it{};

}
#if 0

#endif
