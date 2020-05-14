#include <string>
#include <iostream>
#include <vector>
#include <sstream>
class Product
{
public:
    //Product(std::string n, int v, double p): name{s}, vikt{v}, pris{p} {}
    Product(std::string const &n): name{}, vikt{}, pris{}
    {
/*        std::string s1{};
        std::string s2{};
        std::string s3{};
        std::stringstream ss{n};
        getline(ss, s1, ';');
        std::cout << ss.str();
        ss.ignore();
        getline(ss, s2, ';');
        ss.ignore();
        getline(ss, s3, ';');
        std::cout << s1 << s2 << s3;
        std::stringstream ss1{s1};
        std::stringstream ss2{s2};
        std::stringstream ss3{s3};
        ss1 >> name;
        ss2 >> vikt;
        ss3 >> pris;

        */ // Denna skiten funkar inte



    }
    void print_product()
    {
        std::cout << name << std::endl << vikt << std::endl << pris << std::endl;
        //std::cout << name << ", " << pris/vikt << " kr/kg\n";
    }

private:
    std::string name;
    double vikt;
    double pris;

};


int main()
{
    std::vector<Product> produkter{};
    std::string input{};
    for(int i{1}; i<2; i++)
    {
        std::cout << "Mata in produkt " << i <<": ";
        std::cin >> input;
        produkter.push_back(Product{input});
    }
    produkter.at(0).print_product();
    return 0;
}
