#include <catch2/catch_test_macros.hpp>

#include "../src/rotor.h"
#include <iostream>
#include <string_view>

TEST_CASE("Rotor test", "[rotor]")
{
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };
	REQUIRE(rotor.get_turnover() == 'Q');

	REQUIRE(rotor.get_index_of_char(enigma::ALPHABETS, 'A') == 0);
	REQUIRE(rotor.get_index_of_char(enigma::ALPHABETS, 'Z') == 25);
	REQUIRE(rotor.get_index_of_char(enigma::ALPHABETS, 'c') == -1);	// user can not input chars, but just in case

	//REQUIRE(rotor.pass_through('A') == 'K');
	//rotor.set_position_index(0);
	//REQUIRE(rotor.pass_through('Z') == 'E');
	//REQUIRE(rotor.pass_through('A') == 'M');

	/*rotor.turn_rotor();
	std::cout << "r_index: " << rotor.get_rotor_index() << ", pass: 'A', out: " << rotor.pass_through('A') << "\n";
	std::cout << "r_index: " << rotor.get_rotor_index() << ", rev:  'W', out: " << rotor.reverse_pass_through('W') << "\n";*/
	

}

/*
	ABCDEFGHIJKLMNOPQRSTUVWXYZ
	EKMFLGDQVZNTOWYHXUSPAIBRCJ

	rotor 0, A -> K	(0+1)	mod 26 = 1
	rotor 2, U -> R	(20+3)	mod 26 = 23
	rotor 0, Z -> E	(25+1)	mod 26 = 0

	reverse
	rotor 0, W -> M (13-1)  mod 26 = 12		// empä ole ihan varma.. tarkista meneekö oikein



*/