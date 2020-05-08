#include "json.h"


std::ostream& operator<<(std::ostream& os, Json const & data)
{
    os  <<"{" << " Name: " << data.firstname << ", Surname: " << data.lastname
        << ", ID: " << data.id << ", Courses: [";
        for(unsigned int i = 0; i < data.courses.size(); i++)
        {
            os << data.courses.at(i);
            if(i+1 < data.courses.size() )
            {
                os << ", ";
            }
        }
        os << "]}";
    return os;
}

std::istream& operator>>(std::istream& is, Json &data)
{
    //data.firstnameis.getline(, 99, ':');
    //data.lastnameis.getline(, 99, ':');
    data.id = getline(is, 99, ':');
    std::string s{};
    while( is >> s)
    {
        data.courses.push_back(s);
    }
    return is;
}
