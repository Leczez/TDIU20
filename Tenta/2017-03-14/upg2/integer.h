#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <stdexcept>
class Integer
{
public:
    Integer();
    Integer(int const input);
    explicit operator int () const;
    bool operator==(int const rhs) const;
    bool operator==(Integer const rhs) const;
    bool operator<(Integer const &rhs) const;
    Integer& operator++();
    friend std::ostream& operator<<(std::ostream& os, Integer const &rhs);
private:
    unsigned int unsigned_value;
    bool sign;
};




#endif
