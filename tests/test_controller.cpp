#include <catch2/catch_test_macros.hpp>

#include "../src/core/log.h"
#include "../src/core/controller.h"
#include "raylib.h"

TEST_CASE("Controller test", "[controller]")
{
	enigma::Log::set_level(enigma::LogLevel::ERROR);	// DEBUG level for prints
	Controller controller{};

	REQUIRE(controller.rotors.size() == 3);
	REQUIRE(controller.rotors.at(0).get_wiring() == enigma::ROTOR_I_WIRING);
	REQUIRE(controller.rotors.at(1).get_wiring() == enigma::ROTOR_II_WIRING);
	REQUIRE(controller.rotors.at(2).get_wiring() == enigma::ROTOR_III_WIRING);

	// Original function does not take any parameters (mouse position, key pressed)
	// This is a copypaste of the original function with mouse simulation
	// Apparently this is not technically unit testing, but simulation. I just want to test the logic.
	
	controller.rotors.at(0).set_rotor_index(0);
	controller.rotors.at(1).set_rotor_index(0);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('A') == 'G');

	// Double turnover
	controller.rotors.at(0).set_rotor_index(7);
	controller.rotors.at(1).set_rotor_index(25);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('A') == 'N');
	
	// Single turnover
	controller.rotors.at(0).set_rotor_index(7);
	controller.rotors.at(1).set_rotor_index(24);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('A') == 'E');

	// No turnover
	controller.rotors.at(0).set_rotor_index(6);
	controller.rotors.at(1).set_rotor_index(25);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('A') == 'J');

	// Test backwards if decypher works
	controller.rotors.at(0).set_rotor_index(0);
	controller.rotors.at(1).set_rotor_index(0);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('T') == 'I');
	REQUIRE(controller.debug_handle_key_press_event('E') == 'W');
	REQUIRE(controller.debug_handle_key_press_event('S') == 'T');
	REQUIRE(controller.debug_handle_key_press_event('T') == 'M');
	controller.rotors.at(0).set_rotor_index(0);
	controller.rotors.at(1).set_rotor_index(0);
	controller.rotors.at(2).set_rotor_index(0);
	REQUIRE(controller.debug_handle_key_press_event('I') == 'T');
	REQUIRE(controller.debug_handle_key_press_event('W') == 'E');
	REQUIRE(controller.debug_handle_key_press_event('T') == 'S');
	REQUIRE(controller.debug_handle_key_press_event('M') == 'T');


}