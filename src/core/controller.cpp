#include "controller.h"

Controller::Controller()
{
	//this->rotors.reserve(3);
	//this->rotors.emplace_back(enigma::ROTOR_I_WIRING, enigma::ROTOR_I_TURNOVER);
	//this->rotors.emplace_back(enigma::ROTOR_II_WIRING, enigma::ROTOR_II_TURNOVER);
	//this->rotors.emplace_back(enigma::ROTOR_III_WIRING, enigma::ROTOR_III_TURNOVER);
}

Controller::~Controller()
{
}

void Controller::handle_key_press()
{
	Vector2 mouse_position = GetMousePosition();
	// CHECK IF KEY IS PRESSED => key pointer is set
	if (this->keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
	{
		char unnamed_char = this->keyboard.get_p_pressed_key()->get_label();

		rotor.turn_rotor();
		unnamed_char = rotor.pass_through(unnamed_char);
		unnamed_char = reflector.swap_character(unnamed_char);
		unnamed_char = rotor.reverse_pass_through(unnamed_char);
		lampboard.turn_on_lamp(unnamed_char);
	}

	if (this->keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
	{
		this->lampboard.reset_lamps();
	}
}