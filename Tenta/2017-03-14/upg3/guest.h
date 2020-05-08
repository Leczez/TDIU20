#ifndef GUEST_H
#define GUEST_H
#include <string>
#include <iostream>
#include "poolparty.h"
class Guest
{
public:
    Guest(std::string const &input) : name{input} {}
    virtual ~Guest() = default;
    virtual void update_answer(Pool_Party const &pp) const = 0;
protected:
    std::string name;
};

class Committed_Guest : public Guest
{
public:
    Committed_Guest(std::string const &input) : Guest{input} {}
    ~Committed_Guest() {}
    void update_answer(Pool_Party const &pp) const override {std::cout << "I’m delighted! Of course I’ll come :-D\n";}
private:
};


class Hesitant_Guest : public Guest
{
public:
    Hesitant_Guest(std::string const &input) : Guest{input} {}
    virtual ~Hesitant_Guest();
    void update_answer(Pool_Party const &pp) const override;

    virtual bool will_decline(Pool_Party const &pp) const = 0;
    virtual std::string get_reason() const = 0;
private:
};


class Prude_Guest : public Hesitant_Guest
{
public:
    Prude_Guest(std::string const &input) : Hesitant_Guest{input} {}
    ~Prude_Guest() {}
    bool will_decline(Pool_Party const &pp) const override { return !pp.is_suit_required();}
    std::string get_reason() const override { return "I have a dentist appointment at that time.";}
private:
};

class Busy_Guest : public Hesitant_Guest
{
public:
    Busy_Guest(std::string const &input, int const h) : Hesitant_Guest{input}, hour{h} {}
    ~Busy_Guest() {}
    bool will_decline(Pool_Party const &pp) const override { return hour > pp.get_start_hour();}
    std::string get_reason() const override { return "I can not make it until "+ std::to_string(hour);}
private:
    int hour;
};



#endif
