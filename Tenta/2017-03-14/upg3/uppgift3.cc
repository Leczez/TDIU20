#include "poolparty.h"
#include "guest.h"

int main()
{
  Pool_Party pp{};

  pp.invite( new Busy_Guest{"Beatrice", 19} );
  pp.invite( new Prude_Guest{"Patrik"} );
  pp.invite( new Committed_Guest{"Caspar"} );

  pp.update_all_invites();

  pp.set_start_hour(20);
  pp.require_suit(true);

  pp.update_all_invites();

  return 0;
}
