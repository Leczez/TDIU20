#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "Time.h"

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
    Time t;

    CHECK(t.get_hour() == 0);
    CHECK(t.get_minute() == 0);
    CHECK(t.get_second() == 0);
}

// the following line will halt the compilation process. Move it
// one test case at the time and then start creating your own test
// cases

TEST_CASE ( "Constructor with numeric arguments" )
{
    Time t{12,13,14};
    CHECK(t.get_hour() == 12);
    CHECK(t.get_minute() == 13);
    CHECK(t.get_second() == 14);
}

TEST_CASE ("Constructor with faulty argument")
{
    CHECK_THROWS( Time{41,0,0} );
    CHECK_THROWS( Time{0,99,0} );
    CHECK_THROWS( Time{0,0,99} );
}

TEST_CASE ("String constructor")
{
    Time t{"12:23:12"};

    CHECK(t.get_hour() == 12);
    CHECK(t.get_minute() == 23);
    CHECK(t.get_second() == 12);

    SECTION ("Throws as well")
    {
        CHECK_THROWS( Time{"02:11:74"} );
    }

}

TEST_CASE ("am or pm")
{
    Time t{12,12,31};
    CHECK_FALSE(t.is_am());
    Time t2{1,2,3};
    CHECK(t2.is_am());
}

TEST_CASE ("Convert to string" )
{
    CHECK( Time{12, 9, 0}.to_string()     ==    "12:09:00" );
    CHECK( Time{12, 1, 2}.to_string()     ==    "12:01:02" );
    CHECK( Time{14,03,02}.to_string(true) ==    "02:03:02 pm" );
    CHECK( Time{23, 1, 2}.to_string()     ==    "23:01:02" );
    CHECK( Time{12,03,02}.to_string(true) ==    "12:03:02 pm" );
    CHECK( Time{13, 9, 0}.to_string(true) ==    "01:09:00 pm" );
    CHECK( Time{0, 0, 0}.to_string(true)  ==    "12:00:00 am" );
    CHECK( Time{11, 59, 59}.to_string(true) ==  "11:59:59 am" );
    CHECK( Time{23,03,02}.to_string(true) ==    "11:03:02 pm" );

}

// TODO: Testa så inte operator+ ändrar på objektet. Nu vet vi inte om
// det är + eller = som kommer att ändra på objektet.
TEST_CASE ("Operator +")
{
    Time t{0,0,0};
    CHECK((t + 3).to_string() == "00:00:03");
    CHECK(t.to_string() == "00:00:00");
}

TEST_CASE ("Operator ++")
{
    Time t{0,0,0};
    Time t2{0,1,0};
    t2 = t++;
    CHECK(t.to_string() == "00:00:01");
    CHECK(t2.to_string() == "00:00:00");
}
TEST_CASE (" ++ Operator ")
{
    Time t{0,0,0};
    Time t2{0,1,0};
    t2 = ++t;
    CHECK(t.to_string() == "00:00:01");
    CHECK(t2.to_string() == "00:00:01");

}

// TODO: Samma som på operator+
TEST_CASE("Operator -")
{
    Time t{0,0,0};
    //t = t -(-3);
    CHECK((t-3).to_string() == "23:59:57");

    CHECK(t.to_string() == "00:00:00");

}


TEST_CASE("Operator --")
{
    Time t{0,0,0};
    Time t2{0,1,0};
    t2 = t--;
    CHECK(t.to_string() == "23:59:59");
    CHECK(t2.to_string() == "00:00:00");

}
TEST_CASE(" -- Operator ")
{
    Time t{0,0,0};
    Time t2{0,1,0};
    t2 = --t;
    CHECK(t.to_string() == "23:59:59");
    CHECK(t2.to_string() == "23:59:59");
}

TEST_CASE ("Conversion to string" )
{
    CHECK( string(Time{2,4,1}) == "02:04:01" );
}

TEST_CASE ("Output operator" )
{
    stringstream ss;
    SECTION("Simple output")
    {
        ss << Time{2,5,1};
        CHECK(ss.str() == "02:05:01");
    }

    SECTION("Chained output")
    {
        ss << Time{23,10,32} << "---";
        CHECK(ss.str() == "23:10:32---");
    }
    SECTION("Const time")
    {
        Time const t{23,23,23};
        ss << t;
        CHECK(ss.str() == "23:23:23");
    }
}

// TODO: Testa vad som finns i strömmen efter läsning.
TEST_CASE ("Input operator" )
{
    stringstream ss;
    SECTION("Simple input")
    {
        Time t{};
        ss << "02:05:01";
        CHECK(ss.eof() == false);
        ss >> t;
        CHECK(t.to_string() == "02:05:01");
        CHECK(ss.eof());
    }

    SECTION("Chained input")
    {
        Time t2{};

        Time t3{};
        ss << "23:23:23" << " " << "12:12:12";
        CHECK(ss.eof() == false);
        ss >> t2 >> t3;
        CHECK(ss.eof());
        CHECK(t2.to_string() == "23:23:23");
        CHECK(t3.to_string() == "12:12:12");
    }

    SECTION("Failbit check")
    {
        Time t1{};

        ss << "23:23:23";
        ss >> t1;
        CHECK(t1.to_string() == "23:23:23");
        CHECK(!ss.fail());
        Time t2{};
        ss << "25:23:23";
        ss >> t2;
        CHECK(ss.fail());
    }
}
#if 0
#endif
