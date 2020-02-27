#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
public:
    Connection() = default;
    void set_potential(double const& input);
    double get_potential() const;

protected:


private:
    double potential{};

};


#endif
