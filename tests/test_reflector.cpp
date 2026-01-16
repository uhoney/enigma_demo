#include <catch2/catch_test_macros.hpp>

#include "../src/core/reflector.h"
#include "../src/constants.h"
#include <iostream>

TEST_CASE("Reflector test", "[reflector]")
{
	enigma::Reflector reflector{};

	// Default UKW_A
	REQUIRE(reflector.swap_character(reflector.swap_character('E')) == 'E');
	REQUIRE(reflector.swap_character(reflector.swap_character('C')) == 'C');
	REQUIRE(reflector.swap_character(reflector.swap_character('D')) == 'D');
	REQUIRE(reflector.swap_character('A') == 'E');
	REQUIRE(reflector.swap_character('M') == 'C');
	REQUIRE(reflector.swap_character('Z') == 'D');

	reflector.initialize_UKW(enigma::UKW_B_WIRING);
	REQUIRE(reflector.swap_character('Y') == 'A');
	REQUIRE(reflector.swap_character('L') == 'G');
	REQUIRE(reflector.swap_character('Z') == 'T');

	reflector.initialize_UKW(enigma::UKW_C_WIRING);
	REQUIRE(reflector.swap_character('A') == 'F');
	REQUIRE(reflector.swap_character('L') == 'Z');
	REQUIRE(reflector.swap_character('Z') == 'L');
	
}

/*
*	fixed 1:1 substitute => A->E && E->A
* 
*	index	01234567890123456789012345
*	alpha	ABCDEFGHIJKLMNOPQRSTUVWXYZ
*	refl	EJMZALYXVBWFCRQUONTSPIKHGD	// UKW_A wiring
*/