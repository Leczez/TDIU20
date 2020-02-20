#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
public:
    Connection() = default;
    void set_voltage(double const& input);
    double get_voltage() const;

protected:


private:
    double voltage{};

};


#endif
