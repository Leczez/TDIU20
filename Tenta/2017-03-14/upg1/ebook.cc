#include "ebook.h"


Ebook::Ebook(std::string const& s, int const w, int const r) : content{s}, start_of_page{}, width{w}, rows{r}
{}

std::string Ebook::next_page()
{
    std::ostringstream output{};
    
    //for(int i = 0; i < )
}
