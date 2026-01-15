#include <catch2/catch_test_macros.hpp>

#include "../src/core/log.h"
#include "../src/core/controller.h"

TEST_CASE("Controller test", "[controller]")
{

	enigma::Log::set_level(enigma::LogLevel::DEBUG);

	Controller controller{};

	// REQUIRE(controller.rotors.size() == 3);
	// REQUIRE(controller.rotors.at(0).get_wiring() == enigma::ROTOR_I_WIRING);
	// REQUIRE(controller.rotors.at(1).get_wiring() == enigma::ROTOR_II_WIRING);
	// REQUIRE(controller.rotors.at(2).get_wiring() == enigma::ROTOR_III_WIRING);

	// controller.rotors.at(0).set_rotor_index(7);
	// controller.rotors.at(1).set_rotor_index(25);
	//
	// controller.handle_rotor_turnovers();

	char input_char{'A'};

	controller.debug_handle_key_press_event(input_char);

	controller.rotors.at(0).set_rotor_index(7);
	controller.rotors.at(1).set_rotor_index(25);
	controller.rotors.at(2).set_rotor_index(0);
	controller.debug_handle_key_press_event(input_char);

	controller.rotors.at(0).set_rotor_index(7);
	controller.rotors.at(1).set_rotor_index(24);
	controller.rotors.at(2).set_rotor_index(0);
	controller.debug_handle_key_press_event(input_char);

	controller.rotors.at(0).set_rotor_index(6);
	controller.rotors.at(1).set_rotor_index(25);
	controller.rotors.at(2).set_rotor_index(0);
	controller.debug_handle_key_press_event(input_char);
}