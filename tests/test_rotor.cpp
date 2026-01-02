#include <catch2/catch_test_macros.hpp>

#include "../src/rotor.h"
#include <iostream>
#include <string_view>

TEST_CASE("Rotor test", "[rotor]")
{
	// Alphabets			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	// Rotor I wiring:		"EKMFLGDQVZNTOWYHXUSPAIBRCJ"

	std::string_view wiring{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ" };
	char turnover = 'Q';
	enigma::Rotor rotor{ wiring , turnover };
	REQUIRE(rotor.get_turnover() == turnover);

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