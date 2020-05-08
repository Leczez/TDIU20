#include <iostream>
#include <sstream>
#include <limits>

#include "integer.h"

//=========================================================================
// Test cases
//=========================================================================
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "Default constructor" ) {
  Integer i{};

  CHECK( i == 0 );
}

TEST_CASE( "Output" ) {
  Integer j{4711};
  Integer k{-4711};

  std::ostringstream oss;
  oss << j << k;

  CHECK( oss.str() == "4711-4711" );
}

TEST_CASE( "Compare" ) {
  Integer i{};
  Integer j{4711};
  Integer k{-4711};

  CHECK( i < Integer{1} );
  CHECK( Integer{-1} < i );

  CHECK( j < Integer{4712} );
  CHECK( Integer{4710} < j );

  CHECK( k < Integer{-4710} );
  CHECK( Integer{-4712} < k );
}

TEST_CASE( "Increment" ) {
  Integer i{-2};

  CHECK( ++i == Integer{-1} );
  CHECK( ++i == Integer{0} );
  CHECK( ++i == Integer{1} );
}

TEST_CASE( "Overflow" ) {
  Integer i{ std::numeric_limits<int>::max() };

  CHECK( static_cast<int>(i) == std::numeric_limits<int>::max() );
  CHECK_THROWS( static_cast<int>(++i) );
}
