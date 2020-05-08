#ifndef JSON_H
#define JSON_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
class Json
{
public:
    friend std::ostream& operator<<(std::ostream& os,Json const &data);
    friend std::istream& operator>>(std::istream& is,Json &data);

private:
    std::string firstname, lastname, id;
    std::vector<std::string> courses;
};



#endif
