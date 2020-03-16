#include <iostream>
#include <stdexcept>

using namespace std;

class Resource
{
  // Representerar resursen vi vill begränsa kopiering av
};

class Resource_Control
{
  // Denna klass behöver inte modifieras
  // Den håller reda på antalet kopior som gjors
public:
  Resource_Control(int max) : max_copies{max}, current_copies{1} {}

  // För enkelhets skull ger vi Limited_Resource privat åtkomst
  friend class Limited_Resource;

private:
  const int max_copies;
  int current_copies;
};

class Limited_Resource
{
  // Denna klass måste du färdigställa!
  // Du behöver inte ändra utanför klassen
public:
  Limited_Resource(int max)
    : r{ new Resource{} }, c{ new Resource_Control{max} }
  {}

  // Kopieringskonstruktor
  // Om ytterligare kopior tillåts ska en djup kopia av resursen göras
  // Antal kopior behöver uppdateras och nya kopian behöver åtkomst
  // till samma Resource_Control
  Limited_Resource( Limited_Resource const &input);


  // Flyttkontruktor
  // Det är tillåtet att använda std::swap (gäller hela filen).
  Limited_Resource( Limited_Resource &&input);

  // Kopieringstilldelning
  // Tekniken kopieringskonstruera och byt fungerar.
  Limited_Resource& operator=( Limited_Resource const &rhs);

  // Flytttilldelning
  // Inga tips.
  Limited_Resource& operator=( Limited_Resource &&rhs);
  // Destruktor
  // Här måste både Resource och Resource_Control avallokeras
  // Håll reda på vad som alltid måste avallokeras och vad som bara
  // ska avallokeras när det var sista kopian
  // Se upp för nollpekare i flyttade objekt
  ~Limited_Resource();
private:
  Resource* r;
  Resource_Control* c;
};

Limited_Resource::Limited_Resource( Limited_Resource const &input)
: r{ new Resource{*input.r} }, c{input.c}
{
    if(input.c->max_copies == input.c->current_copies)
    {
        delete r;
        throw std::runtime_error{"TOO MANY COPIES!"};
    }
    else
    {
        c->current_copies++;
    }

}

Limited_Resource::Limited_Resource( Limited_Resource &&input)
: r{nullptr}, c{nullptr}
{
    std::swap(r, input.r);
    std::swap(c, input.c);
}

Limited_Resource& Limited_Resource::operator=( Limited_Resource const &rhs)
{
    Limited_Resource Return_Resource{rhs};
    std::swap((*this).r, Return_Resource.r);
    std::swap((*this).c, Return_Resource.c);
    return *this;
}

Limited_Resource& Limited_Resource::operator=( Limited_Resource &&rhs)
{
    (*this).~Limited_Resource();
    Limited_Resource Return_Resource{std::move(rhs)};
    std::swap((*this).r, Return_Resource.r);
    std::swap((*this).c, Return_Resource.c);
    return *this;
}

Limited_Resource::~Limited_Resource()
{
    if(r != nullptr && c != nullptr)
    {
        delete r;
        c->current_copies--;
        if(c->current_copies == 0)
        {
            delete c;
        }
    }
}

////////////////////////////////////////////////////////////////////////
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("basic limit")
{
  Limited_Resource one{1};

  CHECK_THROWS(Limited_Resource{one});
}

TEST_CASE("object independent limit")
{
  Limited_Resource one{1};
  Limited_Resource other{1};

  CHECK_THROWS(Limited_Resource{one});
  CHECK_THROWS(Limited_Resource{other});
}

TEST_CASE("higher limit")
{
  Limited_Resource three{3};
  Limited_Resource three2{three};
  Limited_Resource three3{three};

  CHECK_THROWS(Limited_Resource{three});
}

TEST_CASE("limit with move")
{
  Limited_Resource one{1};
  Limited_Resource one1{std::move(one)};

  CHECK_THROWS(Limited_Resource{one1});
}

TEST_CASE("limit with assign")
{
  Limited_Resource two{2};
  Limited_Resource other{1};

  other = two;

  CHECK_THROWS(Limited_Resource{two});
  CHECK_THROWS(Limited_Resource{other});
}
TEST_CASE("JOHAN")
{
    Limited_Resource two{1};
    Limited_Resource other = std::move(two);
}
/**/
