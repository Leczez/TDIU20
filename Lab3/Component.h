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
    Connection& A{};
    Connection& B{};

private:





};








#endif
