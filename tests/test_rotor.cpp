#include <catch2/catch_test_macros.hpp>

#include "../src/rotor.h"

TEST_CASE("Rotor test", "[rotor]")
{
	std::string_view rotor1_wiring{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ"};
	char rotor1_turnover = 'Q';
	enigma::Rotor rotor1{ rotor1_wiring, rotor1_turnover };
	
	REQUIRE(rotor1.get_turnover() == rotor1_turnover);
	REQUIRE(rotor1.get_current_position() == 'E');

	rotor1.turn_rotor();
	REQUIRE(rotor1.get_current_position() == 'K');

}