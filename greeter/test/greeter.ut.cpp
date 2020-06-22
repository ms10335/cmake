#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../greeter.hpp"
#include "../person.hpp"

TEST_CASE("Greeter test", "[meet]" ) {
    std::string george = "George";
    Greeter greeter{george};
    REQUIRE(greeter.meet() == "It's nice to meet you " + george + " :)\n");
}

TEST_CASE("Greeter test with Person", "[meet][person]" ) {
    Person george{"George", "Majkel"};
    Greeter greeter{george};
    REQUIRE(greeter.meet() == "It's nice to meet you " + george.getName() + " :)\n");
}

