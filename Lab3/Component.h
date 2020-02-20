#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    Component(std::string n, double data, Connection& first, Connection& last);
    virtual double get_voltage() = 0;
    virtual double get_current() = 0;
    virtual void tick(double const& time_period) = 0;

protected:
    std::string name{};
    Connection A;
    Connection B;
    double value{};

private:

};

class Resistor : public Component
{
public:
    //Resistor(std::string n, double ohm, Connection& first, Connection& last);
    using Component::Component;
    double get_voltage() const;
    double get_current() const;
    void tick(double const& time_period);
protected:

private:
    //double resistance{};
};

class Capacitor : public Component
{
public:
    double get_voltage() const;
    double get_current() const;
    void tick(double const& time_period);
protected:

private:
    double capacitance{};
};


class Battery : public Component
{
public:
    double get_voltage() const;
    double get_current() const;
    void tick(double const& time_period);
protected:

private:
    double voltage{};
};








#endif
