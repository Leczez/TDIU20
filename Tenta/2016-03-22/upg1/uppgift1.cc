#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

class Product_Line
{
public:
    Product_Line(std::string const& p, int a, double s): produktnamn{p}, antal{a}, styckpris{s} {}
    std::string produktnamn;
    int antal;
    double styckpris;
 };
class Receipt
{

public:
    Receipt(int i): kvittonummer{i}, kvittorader{} {}
    void add_product(Product_Line const& produkt)
    {
        kvittorader.push_back(produkt);
    }

    double purchase_value()
    {
        double total{};
        for(auto x : kvittorader)
        {
            total += x.styckpris*x.antal;
        }
        return total;
    }
    void print_receipt()
    {
        std::cout << "Receipt no " << kvittonummer << ":\n";
        for(auto x : kvittorader)
        {
            std::cout << x.produktnamn << ": " << x.antal << "st * "
                      << std::setprecision(2) << std::fixed << x.styckpris << std::endl;
        }
        std::cout << "===\n" << "Köpeskilling: " << purchase_value() << "kr" << std::endl;
    }
private:
    int kvittonummer;
    std::vector<Product_Line> kvittorader;
};

int main()
{
    Receipt kvitto1{1};
    kvitto1.add_product(Product_Line{"apelsin", 2, 5.00});
    kvitto1.add_product(Product_Line{"banan", 5, 7.50});
    kvitto1.add_product(Product_Line{"citron", 1, 15.00});
    kvitto1.print_receipt();

    std::cout << std::endl;
    Receipt kvitto2{2};
    kvitto2.add_product(Product_Line{"gurka", 1, 9.00});
    kvitto2.add_product(Product_Line{"tomat", 5, 18.50});
    kvitto2.add_product(Product_Line{"sallad", 1, 11.00});
    kvitto2.print_receipt();

    std::cout << std::endl;
    Receipt kvitto3{3};
    kvitto3.add_product(Product_Line{"smör", 1, 19.00});
    kvitto3.add_product(Product_Line{"bröd", 10, 24.50});
    kvitto3.add_product(Product_Line{"ost", 1, 48.00});
    kvitto3.print_receipt();
    return 0;
}
