#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
public:
    void set_voltage(double const& input);
    double get_voltage();

protected:


private:
    double voltage{};

};









#endif
