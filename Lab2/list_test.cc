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

//TODO: Ingen check i det här testet. - OKEJ
TEST_CASE ("Default constructor")
{
    List list{};
    stringstream ss{};    //TILLAGD
    ss << list;           //TILLAGD
    CHECK(ss.str() == "");//TILLAGD
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

    SECTION("EDGE CASES")
    {
        stringstream ss{};

        List list{};
        list.insert(10);
        list.insert(11);
        list.insert(12);
        list.insert(13);

        list.remove(0);
        ss << list;
        CHECK(ss.str() == "11 12 13");

        ss.str("");
        ss.clear();
        list.remove(2);
        ss << list;
        CHECK(ss.str() == "11 12");

        ss.str("");
        ss.clear();
        list.remove(1);
        ss << list;
        CHECK(ss.str() == "11");

        ss.str("");
        ss.clear();
        list.remove(0);
        ss << list;
        CHECK(ss.str() == "");
    }

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

//TODO: Testa att kopiera till en lista med data.
//Se kommentaren till copy operator i .cc filen. - OK
TEST_CASE("Assignment operator")
{
    stringstream ss{};

    List list{5,4,10};
    List list2 = list;
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty assignment")
    {
        stringstream ss{};
        List list{};
        List list2 = list;
        ss << list2;
        CHECK(ss.str() == "");
    }

    SECTION("Changes only the assigned object")
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
    SECTION("Assign List with Data already in it")//TILLAGD
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,2,3};
        List list2{10,11,12};

        list = list2;
        ss << list;
        CHECK(ss.str() == "10 11 12");

        ss2 << list2;
        CHECK(ss2.str() == "10 11 12");

        list.remove(0);
        ss.str("");
        ss2.str("");
        ss << list;
        ss2 << list2;
        CHECK(ss.str() == "11 12");
        CHECK(ss2.str() == "10 11 12");
    }
    SECTION("Self assign")//TILLAGD
    {
        stringstream ss{};
        List list{1,2,3};
        list = list;
        ss << list;
        CHECK(ss.str() == "1 2 3");
    }
    SECTION("Empty Self assign")//TILLAGD
    {
        stringstream ss{};
        List list{};
        list = list;
        ss << list;
        CHECK(ss.str() == "");
    }
}

//TODO: Testa så att datat i orginalet (list) inte ändras vid list2.insert tex. -OK
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


    SECTION("Changes only the specified object") //TILLAGD
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2{std::move(list)};

        ss << list;
        CHECK(ss.str() == "");
        ss.str(""); //Clears stream

        ss2 << list2;
        CHECK(ss2.str() == "1 3 5");
        ss2.str(""); //Clears stream

        list2.insert(10);
        list2.insert(2);
        list2.remove(0);
        ss2 << list2;
        CHECK(ss2.str() == "2 3 5 10");
        ss << list;
        CHECK(ss.str() == "");

    }

}

//TODO: Testa self assignment och att orginalet inte ändras.
TEST_CASE("Move operator")
{
    stringstream ss{};

    List list{5,4,10};
    List list2{};
    list2 = std::move(list);
    ss << list2;
    CHECK(ss.str() == "4 5 10");

    SECTION("Empty move")
    {
        stringstream ss{};
        List list{};
        List list2{};
        list2 = std::move(list);
        ss << list2;
        CHECK(ss.str() == "");
    }

    SECTION("Data in right hand side object") //TILLAGD
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2{};
        list2 = std::move(list);

        ss << list;
        CHECK(ss.str() == "");
        ss.str(""); //CLEARS STREAM

        ss2 << list2;
        CHECK(ss2.str() == "1 3 5");
        ss2.str(""); //CLEARS STREAM

        list2.insert(10);
        list2.insert(2);
        list2.remove(0);
        ss2 << list2;
        CHECK(ss2.str() == "2 3 5 10");
        ss << list;
        CHECK(ss.str() == "");
    }

    SECTION("Data in left hand side object") //TILLAGD
    {
        stringstream ss{};
        stringstream ss2{};
        List list{};
        List list2{1,3,5};
        list2 = std::move(list);

        ss << list;
        CHECK(ss.str() == "");
        ss.str(""); //Clears stream

        ss2 << list2;
        CHECK(ss2.str() == "");
        ss2.str(""); //Clears stream

        list2.insert(10);
        list2.insert(2);
        list2.remove(0);

        ss2 << list2;
        CHECK(ss2.str() == "10");
        ss << list;
        CHECK(ss.str() == "");
    }

    SECTION("Data already in both objects") //TILLAGD
    {
        stringstream ss{};
        stringstream ss2{};
        List list{1,3,5};
        List list2{10,15};
        list2 = std::move(list);

        ss << list;
        CHECK(ss.str() == "");
        ss.str(""); //CLEARS STREAM

        ss2 << list2;
        CHECK(ss2.str() == "1 3 5");
        ss2.str(""); //CLEARS STREAM

        list2.insert(10);
        list2.insert(2);
        list2.remove(0);
        ss2 << list2;
        CHECK(ss2.str() == "2 3 5 10");
        ss << list;
        CHECK(ss.str() == "");
    }

    SECTION("Self Move")//TILLAGD
    {
        stringstream ss{};
        List list{1,2,3};
        list = std::move(list);
        ss << list;
        CHECK(ss.str() == "1 2 3");
    }

    SECTION("Empty Self Move")//TILLAGD
    {
        stringstream ss{};
        List list{};
        list = std::move(list);
        ss << list;
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
    SECTION("Operator =")
    {
        List list{1,2,3,4,5};
        List::List_iterator it = list.begin();
    }

    SECTION("Operator ==")
    {
        List list{1,2,3,4,5};
        List list2{4,5,6,7,8};

        List::List_iterator itA = list.begin();
        List::List_iterator itB = list.begin();
        CHECK( itA == itB );

        List::List_iterator itC = list2.begin();
        CHECK_FALSE( itA == itC );
    }

    SECTION("Operator !=")
    {
        List list{1,2,3,4,5};
        List list2{4,5,6,7,8};

        List::List_iterator itA = list.begin();
        List::List_iterator itB = list.begin();

        CHECK_FALSE( itA != itB );

        List::List_iterator itC = list2.begin();
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
