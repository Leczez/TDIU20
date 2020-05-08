#define WITH_TEMPLATE

#ifndef POOLPARTY_H
#define POOLPARTY_H

#include <vector>

class Guest;

class Pool_Party
{
public:
  Pool_Party(int sh = 18, bool sr = false);
  ~Pool_Party();

  void invite(Guest const* g);

  void update_all_invites() const;

  int  get_start_hour() const;
  void set_start_hour(int i);

  bool is_suit_required() const;
  void require_suit(bool b);

private:
  int start_hour;
  bool suit_required;
  std::vector<Guest const*> invites;
};

#endif
