#include <catch2/catch_test_macros.hpp>

#include "../src/rotor.h"
#include <iostream>
#include <string_view>

TEST_CASE("Rotor test", "[rotor]")
{
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };
	REQUIRE(rotor.get_turnover() == 'Q');

	rotor.add_position_index();
	REQUIRE(rotor.rotor_substitute() == 'K');
	REQUIRE(rotor.rotor_reverse_substitute() == 'B');
	rotor.set_position_index(25);							// Last index
	REQUIRE(rotor.rotor_substitute() == 'J');
	REQUIRE(rotor.rotor_reverse_substitute() == 'Z');
	rotor.add_position_index();								// should flip to index[0]
	REQUIRE(rotor.rotor_substitute() == 'E');
	REQUIRE(rotor.rotor_reverse_substitute() == 'A');
}