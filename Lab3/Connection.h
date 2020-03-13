#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

class Connection
{
public:
    Connection() = default;
    Connection(std::string input);
    void set_potential(double const& input);
    double get_potential() const;
    std::string get_name() const;

protected:

private:
    double potential{};
    std::string name{};
};


#endif
