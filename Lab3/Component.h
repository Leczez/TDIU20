#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

class Component
{
public:
    virtual double get_voltage() = 0;
    virtual double get_current() = 0;
    virtual void tick() = 0;

protected:
    std::string name{};
    //Connection& A{};
    //Connection& B{};

private:

};

class Resistor : public Component
{
public:
    double get_voltage() const;
    double get_current() const;
    void tick();
protected:

private:
    double resistance{};
};

class Capacitor : public Component
{
public:
    double get_voltage() const;
    double get_current() const;
    void tick();
protected:

private:
    double capacitance{}
};


class Battery : public Component
{
public:
    double get_voltage() const;
    double get_current() const;
    void tick();
protected:

private:
    double voltage{};
};








#endif
