#include <catch2/catch_test_macros.hpp>

#include "../src/core/log.h"
#include "../src/core/controller.h"

TEST_CASE("Controller test", "[controller]")
{

	enigma::Log::set_level(enigma::LogLevel::DEBUG);

	Controller controller{};

	REQUIRE(controller.rotors.size() == 3);
	REQUIRE(controller.rotors.at(0).get_wiring() == enigma::ROTOR_I_WIRING);
	REQUIRE(controller.rotors.at(1).get_wiring() == enigma::ROTOR_II_WIRING);
	REQUIRE(controller.rotors.at(2).get_wiring() == enigma::ROTOR_III_WIRING);

	controller.check_rotor_turnovers();

	controller.rotors.at(0).set_position_index(6);

	controller.check_rotor_turnovers();
}



//Vector2 virtual_mouse_A{300.0f, 475.0f};    // 'A' key position
//Vector2 virtual_mouse_Z{450.0f, 550.0f};    // 'Z' key position
//Controller controller{};
//REQUIRE(controller.rotors.size() == 3);
//// Simulate pressing 'A'
//controller.keyboard.isKeyPressed(virtual_mouse_A, true);
//REQUIRE(controller.keyboard.get_p_pressed_key() != nullptr);
//REQUIRE(controller.keyboard.get_p_pressed_key()->get_label() == 'A');
//controller.check_rotor_turnovers();
//REQUIRE(controller.rotors.at(0).get_rotor_index() == 1); // First rotor should have turned
//controller.keyboard.isKeyReleased(true);
//REQUIRE(controller.keyboard.get_p_pressed_key() == nullptr);
//// Simulate pressing 'Z'
//controller.keyboard.isKeyPressed(virtual_mouse_Z, true);
//REQUIRE(controller.keyboard.get_p_pressed_key() != nullptr);
//REQUIRE(controller.keyboard.get_p_pressed_key()->get_label() == 'Z');
//controller.check_rotor_turnovers();
//REQUIRE(controller.rotors.at(0).get_rotor_index() == 2); // First rotor should have turned again
//controller.keyboard.isKeyReleased(true);
//REQUIRE(controller.keyboard.get_p_pressed_key() == nullptr);