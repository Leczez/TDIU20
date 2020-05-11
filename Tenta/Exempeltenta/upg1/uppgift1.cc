#include <iostream>
#include <vector>



class Card
{
private:
    int color;
    int value;
public:
    Card(const int c, const int v): color{c}, value{v}
    {}
    int get_value() const {
        if(value < 10)
        return value;
        else return 10;
    }
    void print_card() const{
        if(color==0)
        {std::cout << "Hjärter";}
        if(color==1)
        {std::cout << "Spader";}
        if(color==2)
        {std::cout << "Ruter";}
        if(color==3)
        {std::cout << "Klöver";}
        std::cout << " ";
        if(value > 1 && value < 11)
        {std::cout << value;}
        else if(value==1)
        {std::cout << "Ess";}
        else if(value==11)
        {std::cout << "Knekt";}
        else if(value==12)
        {std::cout << "Dam";}
        else if(value==13)
        {std::cout << "Kung";}
        std::cout << std::endl;
    }

};

class Hand
{
public:
    Hand():all_cards{}
    {}
    void add_card(const Card& kort)
    {
        all_cards.push_back(kort);
    }

    void print_hand() const {
        for(Card x: all_cards)
        {
            x.print_card();
        }

    }
    void print_value() const{
        int total{};
        int aces{};
        for(Card x: all_cards)
        {
            total +=x.get_value();
            if(x.get_value()==1)
            {aces++;}
        }
        while(aces > 0)
        {
            if(total <= 11)
            {total += 10;}
            aces--;
        }

        std::cout << "Värde: " << total << std::endl;
    }
private:
    std::vector<Card> all_cards;
};

int main()
{
    Card c1{1,1}; //Hjärter 5
    Card c2{0,7}; //Klöver Ess

    Hand h1{};
    h1.add_card(Card{1,1});
    h1.add_card(c2);
    h1.print_hand();
    h1.print_value();

    std::cout << '\n';

    Card c3{3,11};
    Card c4{2,12};
    Card c5{2,7};
    Hand h2{};
    h2.add_card(c3);
    h2.add_card(c4);
    h2.add_card(c5);
    h2.print_hand();
    h2.print_value();

    std::cout << '\n';

    Card c6{2,1};
    Card c7{0,9};
    Card c8{1,1};
    Hand h3{};
    h3.add_card(c6);
    h3.add_card(c7);
    h3.add_card(c8);
    h3.print_hand();
    h3.print_value();

    return 0;
}
