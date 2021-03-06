#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    Component(std::string n, double data, Connection &first, Connection &last);
    virtual ~Component() = default;
    //Component(std::string n, double data);
    virtual double get_voltage() const;
    virtual double get_current() const = 0;
    virtual void tick(double const& time_period) = 0;
    std::string get_name() const;
    virtual void set_nodes(Connection& node1, Connection& node2);
protected:
    std::string name;
    //Connection dummynode{};
    double value;
    Connection &A;
    Connection &B;
private:

};

class Resistor : public Component
{
public:
    using Component::Component;
    double get_current() const;
    void tick(double const& time_period);
protected:

private:

};

class Capacitor : public Component
{
public:
    using Component::Component;
    double get_current() const;
    void tick(double const& time_period);
protected:

private:
    double charge{};
};


class Battery : public Component
{
public:
    using Component::Component;
    double get_voltage() const override;
    double get_current() const;
    void tick(double const& time_period);

protected:

private:
};



#endif
