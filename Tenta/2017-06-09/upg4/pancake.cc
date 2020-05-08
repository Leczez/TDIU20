#include <iostream>
#include <vector>
#include <string>



class Condiment
{
public:

    virtual ~Condiment() {};
    virtual void eat() const = 0;
    double price() const { return cost; }
protected:
    Condiment(double const p): cost{p} {}
private:
    double cost;
};


class Banana: public Condiment
{
public:
    Banana() : Condiment::Condiment(0.30){}
    ~Banana() {}
    void eat() const override { std::cout << "banana slices";}
};

class ChokoBits: public Condiment
{
public:
    ChokoBits() : Condiment::Condiment(0.45){}
    ~ChokoBits() {}
    void eat() const override { std::cout << "chocolate bits!";}
};

class Syrup: public Condiment
{
public:
    Syrup(std::string s) : Condiment::Condiment(0.20), syruptype{s} {}
    ~Syrup() {}
    void eat() const override { std::cout << syruptype;}
private:
    std::string syruptype{};
};

class Pancake
{
public:
    Pancake(): tillbehor{} {}
    void add(Condiment* con) {tillbehor.push_back(con);}
    void eat();
    double price();
private:
    std::vector<Condiment*> tillbehor;
};


void Pancake::eat()
{
    if(tillbehor.size() > 0)
    {
        std::cout << "Mmm, a pancake with: ";
        for(auto x : tillbehor)
        {
            x->eat();
            std::cout << " ";
        }
    }
    else
    {
        std::cout << "Hmm, a plain pancake.";
    }
    std::cout << std::endl;

}

double Pancake::price()
{
    double total{0.75};
    for(Condiment* x : tillbehor)
    {
        total += x->price();
    }
    return total;
}
int main()
{
    // Skapa följande objekt dynamiskt och lagra i en vector
    // Pankaka utan tillbehör
    // Pannkaka med Chokladsirap och bananbitar
    // Pannkaka med lönnsirap
    // Pannkaka med chokladbitar
    Pancake pannkaka{};
    pannkaka.add(new Banana);
    pannkaka.add(new Syrup{"CHOKLAD"});
    pannkaka.add(new ChokoBits);
    pannkaka.eat();
    // Anropa eat-funktionen på varje pannkaka, utskriften bör då bli
    // Hmm, a plain pancake.
    // Mmm, a pancake with chocolate syrup and banana slices
    // Mmm, a pancake with maple syrup
    // Mmm, a pancake with chocolate bits

    // Beräkna totala priset genom att anropa price på varje pannkaka. Det borde bli $4.15.
    double total_price = pannkaka.price();

    std::cout << "Your price is $" << total_price << '\n';
}
