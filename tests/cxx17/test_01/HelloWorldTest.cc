#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include <string>
#include <cxx17/HelloWorld.h>
#include "Util.h"


TEST_CASE("Test_01", "Hello World Test 01")
{
    std::string caption = "Hello World from C++17";
    cxx17::HelloWorld h(caption);


    REQUIRE(h.caption()== caption);
    
}


