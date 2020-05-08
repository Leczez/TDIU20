#include <iostream>
#include <string>
#include <vector>
#include "guest.h"
#include "poolparty.h"


Pool_Party::Pool_Party(int sh, bool sr)
  : start_hour{sh}, suit_required{sr}, invites{}
{
}

Pool_Party::~Pool_Party()
{
  for ( auto && g : invites )
  {
    delete g;
  }
}

void Pool_Party::invite(Guest const* g)
{
  invites.push_back(g);
}

void Pool_Party::update_all_invites() const
{
  using std::cout;

  cout << std::endl << "POOL PARTY at " << start_hour;

  if ( suit_required )
  {
    cout << " (bring bath suit to get in)";
  }
  cout << std::endl;

  for ( auto && g : invites )
  {
    g->update_answer(*this);
  }
}

int  Pool_Party::get_start_hour() const
{
  return start_hour;
}

void Pool_Party::set_start_hour(int i)
{
  start_hour = i;
}

bool Pool_Party::is_suit_required() const
{
  return suit_required;
}

void Pool_Party::require_suit(bool b)
{
  suit_required = b;
}
