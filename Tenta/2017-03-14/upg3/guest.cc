#include "guest.h"

void Hesitant_Guest::update_answer(Pool_Party const &pp) const
{
    if(will_decline(pp))
    {
        std::cout << "Sorry, " << get_reason() << std::endl;
    }
    else
    {
        std::cout << "I’m delighted! Of course I’ll come :-D" << std::endl;
    }
}
