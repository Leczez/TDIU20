#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Container
{
public:

    virtual ~Container() = default;
    virtual void print() const
    {
        cout << description;
        if(stackable)
        {
            cout << " [stapelbar]";
        }

    }

protected:
    Container(const string& d, const bool s): description{d}, stackable{s}
    {
    }
    string description;
    bool stackable;
private:
    Container(const Container & ) = delete;
    Container(Container &&) = delete;
    Container& operator=(const Container & ) = delete;
};

class Hot_Container : public Container
{
public:
    Hot_Container(const string& d, const bool s, const bool e = false): Container(d,s), ear{e}
    {

    }
    void print() const override
    {
        Container::print();
        if(ear)
        {
            cout << " med öra";
        }
    }
protected:
    bool ear;
};


class Thermos: public Hot_Container
{
public:
    Thermos(const string& d, const bool s): Hot_Container(d,s)
    {}

    void print() const override
    {
        Hot_Container::print();
        cout << " (termos)";
    }
private:

};

class Cold_Container: public Container
{
public:
    Cold_Container(const string& d, const bool s, const string& m): Container(d,s), material{m}
    {}

    void print() const override
    {
        Container::print();
        cout << " (" << material << ")";
    }
private:
    string material;

};


int main()
{
    vector<Container const *> containers {
        new Thermos{"Termosmugg", false}, // termosmugg, ej stapelbar
        new Cold_Container{"Vattenglas", true, "glas"}, // Stapelbart glas
        new Hot_Container{"E-kolv", false}, // ej stapelbar e-kolv utan öra
        new Hot_Container{"Kaffekopp", true, true} // stapelbar kaffekopp med öra
    };
    for ( Container const * c : containers )
    {
        c->print();
        cout << endl;
    }
    // Ska skriva ut föjande:
    // Termosmugg (termos)
    // Vattenglas [stapelbar] (glas)
    // E-kolv
    // Kaffekopp [stapelbar] med öra
    Hot_Container c{"hej", false};
    //Hot_Container c2{c};
    for ( Container const * c : containers )
    {
        delete c;
    }
    containers.clear();
}
