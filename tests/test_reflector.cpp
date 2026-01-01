#include <catch2/catch_test_macros.hpp>

#include "../src/reflector.h"

TEST_CASE("Reflector test", "[reflector]")
{
	enigma::Reflector reflector{};
	// Default UKW_A
	REQUIRE(reflector.swap_character('A') == 'E');
	REQUIRE(reflector.swap_character('L') == 'F');
	REQUIRE(reflector.swap_character('Z') == 'D');
	REQUIRE(reflector.swap_character('t') == '0');

	reflector.initialize_UKW(reflector.get_UKW_B_WIRING());
	REQUIRE(reflector.swap_character('A') == 'Y');
	REQUIRE(reflector.swap_character('L') == 'G');
	REQUIRE(reflector.swap_character('Z') == 'T');

	reflector.initialize_UKW(reflector.get_UKW_C_WIRING());
	REQUIRE(reflector.swap_character('A') == 'F');
	REQUIRE(reflector.swap_character('L') == 'Z');
	REQUIRE(reflector.swap_character('Z') == 'L');
}