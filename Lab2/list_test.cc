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
    stringstream ss{};
    List list{};
    list.insert(10);
    ss << list;
    CHECK(ss.str() == "10");
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

TEST_CASE("Initalizer constructor")
{
    stringstream ss{};
    List list{5,4,10};
    ss << list;
    CHECK(ss.str() == "4 5 10");
}

TEST_CASE("Listsize")
{
    List list{5,4,10};
    CHECK(list.size() == 3);
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

    SECTION("EMPTY LIST")
    {
        List list{};
        CHECK(list.size() == 0);
    }

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
    List list2{};
    list2 = std::move(list);
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty copy")
    {
        stringstream ss{};
        List list{};
        List list2;
        list2 = std::move(list);
        ss << list2;
        CHECK(ss.str() == "");
    }

    SECTION("Extra Tests")
    {
        stringstream ss{};
        List list{1,3,5};
        List list2;
        list2 = std::move(list);
        list2.insert(10);
        list2.remove(0);
        ss << list2;
        CHECK(ss.str() == "3 5 10");

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
        CHECK_THROWS(list[5]);
    }

    SECTION("Empty List")
    {
        List list{};
        CHECK_THROWS(list[0]);
    }
}

TEST_CASE("List_Iterator")
{
    SECTION("Empty Constructor")
    {
        List::List_iterator{};
    }

    SECTION("Operator =")
    {
        List list{1,2,3,4,5};
        List::List_iterator it{};
        it = list.begin();
    }

    SECTION("Operator ==")
    {
        List list{1,2,3,4,5};
        List list2{4,5,6,7,8};

        List::List_iterator itA{};
        List::List_iterator itB{};
        itA = list.begin();
        itB = list.begin();
        CHECK( itA == itB );

        List::List_iterator itC{};
        itC = list2.begin();
        CHECK_FALSE( itA == itC );
    }

    SECTION("Operator !=")
    {
        List list{1,2,3,4,5};
        List list2{4,5,6,7,8};

        List::List_iterator itA{};
        List::List_iterator itB{};
        itA = list.begin();
        itB = list.begin();
        CHECK_FALSE( itA != itB );

        List::List_iterator itC{};
        itC = list2.begin();
        CHECK( itA != itC );
    }

    SECTION("operator*")
    {
        List list{1,2,3,4,5};
        List::List_iterator itA = list.begin();
        CHECK(*itA == 1);

        List::List_iterator itB = list.end();
        CHECK_THROWS(*itB); //NOT VALID BECAUSE WE TRY TO READ THE LAST SENTINELS VALUE

    }

    SECTION("++operator")
    {
        List list{1,2,3,4,5};
        List::List_iterator itA = list.begin();
        CHECK(*itA == 1);
        ++itA;
        CHECK(*itA == 2);
        ++itA;
        CHECK(*itA == 3);
        ++itA;
        CHECK(*itA == 4);
        ++itA;
        CHECK(*itA == 5);
        ++itA; //VALID SINCE WE ADVANCE OUR LIST TO THE END SENTINEL
        CHECK_THROWS(++itA); // NOT VALID SINCE WE ARE AT THE END SENTINEL AND TRY TO ADVANCE

        List::List_iterator itB = list.end(); //SAME AS THE ABOVE TEST
        CHECK_THROWS(++itB);

        SECTION("UNINITIATED LIST")
        {
            List::List_iterator itA{};
            CHECK_THROWS(*itA);
        }
    }

    SECTION("FOR-LOOP")
    {
        ostringstream ss;
        List lista{2,5,7};
        for(List::List_iterator it = lista.begin(); it != lista.end(); ++it)
        {
            ss << *it << " ";
        }
        CHECK(ss.str() == "2 5 7 ");
    }

    SECTION("EMPTY FOR-LOOP")
    {
        ostringstream ss;
        List lista{};
        for(List::List_iterator it = lista.begin(); it != lista.end(); ++it)
        {
            ss << *it << " ";
        }
        CHECK(ss.str() == "");
    }
}

#if 0

#endif
