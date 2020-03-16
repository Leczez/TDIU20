#include <stdexcept>
#include <iostream>
// add your Color class here
// you may but are not required to add a header file
// do not modify anything else
class Color
{
public:
    Color(int r, int g, int b, int a);
    Color(int r, int g, int b);
    explicit Color(int a);
    friend std::ostream& operator<<(std::ostream& os, Color const &c);
    Color operator+(Color const &rhs) const;
    Color operator+(int const rhs) const;
    friend Color operator+(int const lhs, Color const &rhs);
private:
    bool color_out_of_range(int n) const;
    int R,G,B,A;

};

Color::Color(int r, int g, int b, int a): R{r}, G{g}, B{b}, A{a}
{
    if(color_out_of_range(r) || color_out_of_range(g) || color_out_of_range(b) || color_out_of_range(a) )
    {
        throw std::range_error{"COLOR OUT OF RANGE"};
    }
};

Color::Color(int r, int g, int b): R{r}, G{g}, B{b}, A{255}
{
    if(color_out_of_range(r) || color_out_of_range(g) || color_out_of_range(b) )
    {
        throw std::range_error{"COLOR OUT OF RANGE"};
    }
}

Color::Color(int n): R{n}, G{n}, B{n}, A{255}
{
    if(color_out_of_range(n))
    {
        throw std::range_error{"COLOR OUT OF RANGE"};
    }
}

bool Color::color_out_of_range(int n) const
{
    return (n > 255 || n < 0);
}

std::ostream& operator<<(std::ostream& os, Color const &c)
{
    os << "{" << c.R << ", " << c.G << ", " << c.B << "}";
    return os;
}

Color Color::operator+(Color const &rhs) const
{
    Color ReturnColor{(*this)};
    ReturnColor.R += rhs.R;
    ReturnColor.R /= 2;
    ReturnColor.G += rhs.G;
    ReturnColor.G /= 2;
    ReturnColor.B += rhs.B;
    ReturnColor.B /= 2;
    return ReturnColor;
}

Color Color::operator+(int const rhs) const
{
    Color ReturnColor{(*this)};
    ReturnColor.R += rhs;
    ReturnColor.R /= 2;
    ReturnColor.G += rhs;
    ReturnColor.G /= 2;
    ReturnColor.B += rhs;
    ReturnColor.B /= 2;
    return ReturnColor;
}

Color operator+(int const lhs, Color const &rhs)
{
    Color ReturnColor{(rhs)};
    ReturnColor.R += lhs;
    ReturnColor.R /= 2;
    ReturnColor.G += lhs;
    ReturnColor.G /= 2;
    ReturnColor.B += lhs;
    ReturnColor.B /= 2;
    return ReturnColor;
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>

std::string str(Color const& c)
{
  std::ostringstream oss;
  oss << c;
  return oss.str();
}

TEST_CASE("construction")
{
    CHECK_NOTHROW( (Color{1,255,0,255}) );
    CHECK_NOTHROW( (Color{100,200,0}) );
    CHECK_NOTHROW( (Color{75,140,60}) );
    CHECK_NOTHROW( (Color{128}) );
    CHECK_THROWS( (Color{256,-1,256,-1}) );
}

TEST_CASE("print")
{
  CHECK( str(Color{50,80,20,128}) == "{50, 80, 20}");
}

TEST_CASE("add color")
{
  Color a{100,200,0};
  Color b{50,80,120};
  Color c{75,140,60};

  REQUIRE( str(Color{50,80,20}) == "{50, 80, 20}");

  CHECK( str(a+b) == str(c) );
  CHECK( str(a+c) != str(b) );
  CHECK( str(b+c) != str(a) );
}

TEST_CASE("add grayscale")
{
  Color a{100,200,0};
  Color b{100,150,50};

  REQUIRE( str(Color{50,80,20}) == "{50, 80, 20}");

  CHECK( str(a+100) == str(b) );
  CHECK( str(100+a) == str(b) );
}
