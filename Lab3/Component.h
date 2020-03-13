#ifndef COMPONENT_H
#define COMPONENT_H

#include "Connection.h"
#include <string>

//TODO: Att lagra en variabel "value" som inte har ett definierat
//värde är dålig objektorientering. Skapa istället de variabler där de
//behövs i subklasserna. OK!

//TODO: Ni ska använda override på överlagrade funktioner. OK!

//TODO: Ni initierar inte charge vid skapad Capacitor. OK!

class Component
{
public:
    Component(std::string n, Connection &first, Connection &last);
    virtual ~Component() = default;
    virtual double get_voltage() const;
    virtual double get_current() const = 0;
    virtual void tick(double const& time_period) = 0;
    std::string get_name() const;
protected:
    std::string name;
    Connection &A;
    Connection &B;
private:

};

class Resistor : public Component
{
public:
    Resistor(std::string n, double data, Connection &first, Connection &last);
    double get_current() const override;
    void tick(double const& time_period) override;
protected:

private:
    double resistance;
};

class Capacitor : public Component
{
public:
    Capacitor(std::string n, double data, Connection &first, Connection &last);
    double get_current() const override;
    void tick(double const& time_period) override;
protected:

private:
    double capacitance;
    double charge;
};


class Battery : public Component
{
public:
    Battery(std::string n, double data, Connection &first, Connection &last);
    double get_voltage() const override;
    double get_current() const override;
    void tick(double const& time_period) override;

protected:

private:
    double voltage;
};



#endif
