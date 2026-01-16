#include <catch2/catch_test_macros.hpp>

#include "../src/core/rotor.h"
#include <iostream>
#include <string_view>

TEST_CASE("Rotor test", "[rotor]")
{
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };
	REQUIRE(rotor.get_turnover_char() == 'Q');

	REQUIRE(rotor.get_index_of_char(enigma::ALPHABETS, 'A') == 0);
	REQUIRE(rotor.get_index_of_char(enigma::ALPHABETS, 'Z') == 25);

	rotor.turn_rotor();		// count from 0, now index = 1
	REQUIRE(rotor.pass_through('A') != 'A');
	REQUIRE(rotor.pass_through('Z') != 'Z');
	REQUIRE(rotor.pass_through('A') == 'K');			// (char_alpha + rotor) = 0 + 1 mod 26 = 1, wiring_index[1] = K
	REQUIRE(rotor.pass_through('M') == 'W');
	REQUIRE(rotor.pass_through('Z') == 'E');
	REQUIRE(rotor.reverse_pass_through('E') == 'Z');	// (char_wiring - rotor +26) = 0-1+26 mod 26 = 25, alpha_index[25] = Z
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('A')) == 'A');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('M')) == 'M');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('Z')) == 'Z');

	rotor.turn_rotor();		// rotor_index = 2
	REQUIRE(rotor.pass_through('A') != 'A');
	REQUIRE(rotor.pass_through('Z') != 'Z');
	REQUIRE(rotor.pass_through('A') == 'M');
	REQUIRE(rotor.pass_through('M') == 'Y');			// (char_alpha + rotor) = 12 + 2 mod 26 = 14, wiring_index[14] = Y
	REQUIRE(rotor.pass_through('Z') == 'K');
	REQUIRE(rotor.reverse_pass_through('Y') == 'M');	// (char_wiring - rotor +26) = 14-2+26 mod26 =12 , alpha_index[12] = M
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('A')) == 'A');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('M')) == 'M');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('Z')) == 'Z');

	rotor.set_rotor_index(25);
	REQUIRE(rotor.pass_through('A') != 'A');
	REQUIRE(rotor.pass_through('Z') != 'Z');
	REQUIRE(rotor.pass_through('A') == 'J');
	REQUIRE(rotor.pass_through('M') == 'T');
	REQUIRE(rotor.pass_through('Z') == 'C');			// (char_alpha + rotor) = 25 + 25 mod 26 = 24, wiring_index[24] = C
	REQUIRE(rotor.reverse_pass_through('J') == 'A');	// (char_wiring - rotor +26) = 25-25+26 mod26 = 0, alpha_index[0] = A
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('A')) == 'A');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('A')) == 'A');
	REQUIRE(rotor.pass_through(rotor.reverse_pass_through('A')) == 'A');

}

/*
*	index	01234567890123456789012345
*	alpha	ABCDEFGHIJKLMNOPQRSTUVWXYZ
*	wiring	EKMFLGDQVZNTOWYHXUSPAIBRCJ  // ROTOR_I_WIRING
*/