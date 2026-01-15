#include "controller.h"

Controller::Controller()
{
	this->rotors.reserve(3);
	this->rotors.emplace_back(enigma::ROTOR_I_WIRING, enigma::ROTOR_I_TURNOVER);
	this->rotors.emplace_back(enigma::ROTOR_II_WIRING, enigma::ROTOR_II_TURNOVER);
	this->rotors.emplace_back(enigma::ROTOR_III_WIRING, enigma::ROTOR_III_TURNOVER);
}

Controller::~Controller()
{
}

void Controller::handle_key_press_event()
{
	Vector2 mouse_position = GetMousePosition();

	// CHECK IF KEY IS PRESSED => key pointer is set
	if (this->keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
	{
		// Get the pressed key character
		char temp_char{this->keyboard.get_pressed_key()->get_label()};

		// Turn first rotor and check if others need to turn
		this->handle_rotor_turnovers();

		// run current (char) through rotors 1,2,3
		for (auto &rotor : this->rotors)
		{
			temp_char = rotor.pass_through(temp_char);
		}

		// swap and change direction
		temp_char = this->reflector.swap_character(temp_char);

		// run char through rotors in reverse
		for (auto rotor = this->rotors.rbegin(); rotor != this->rotors.rend(); ++rotor)
		{
			temp_char = rotor->reverse_pass_through(temp_char);
		}

		// turn on lamp for output char
		this->lampboard.turn_on_lamp(temp_char);
	}

	// Turn off lamps when key is released => key pointer is reset
	if (this->keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
	{
		this->lampboard.reset_lamps();
	}
}

char Controller::debug_handle_key_press_event(char &input_char)
{
	char temp_char{input_char};

	// DEBUG -------------------------------------------
	enigma::Log::debug("Before checks:");
	enigma::Log::debug("reflector: %s", this->reflector.get_wiring().c_str());
	for (auto &i : this->rotors)
	{
		enigma::Log::debug("Rotor wire: %s, rotor index: %d, rotor turnover: %d", i.get_wiring().c_str(), i.get_rotor_index(), i.get_turnover_index());
	}
	// -------------------------------------------------

	// check & turn rest of rotors if needed
	this->handle_rotor_turnovers();

	// DEBUG -------------------------------------------
	enigma::Log::debug("After checks and ALL rolls");
	for (auto &i : this->rotors)
	{
		enigma::Log::debug("Rotor wire: %s, rotor index: %d, rotor turnover: %d", i.get_wiring().c_str(), i.get_rotor_index(), i.get_turnover_index());
	}
	// -------------------------------------------------

	// run through rotors 1,2,3
	for (auto &rotor : this->rotors)
	{
		temp_char = rotor.pass_through(temp_char);
	}

	// swap and change direction
	temp_char = this->reflector.swap_character(temp_char);

	// run through rotors in reverse
	for (auto rotor = this->rotors.rbegin(); rotor != this->rotors.rend(); ++rotor)
	{
		temp_char = rotor->reverse_pass_through(temp_char);
	}

	enigma::Log::debug("output: %c", temp_char);

	return temp_char;
}

void Controller::handle_rotor_turnovers()
{
	int temp0 = this->rotors.at(0).get_rotor_index();
	int temp1 = this->rotors.at(1).get_rotor_index();

	// First rotor ALWAYS turns
	this->rotors.at(0).turn_rotor();

	if (this->rotors.at(0).get_turnover_index() == temp0)
	{
		this->rotors.at(1).turn_rotor();
	}

	if (this->rotors.at(1).get_turnover_index() == temp1 &&
		(this->rotors.at(0).get_turnover_index() == temp0))
	{
		this->rotors.at(2).turn_rotor();
	}
}
