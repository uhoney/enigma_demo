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

void Controller::handle_key_press()
{
	Vector2 mouse_position = GetMousePosition();

	// CHECK IF KEY IS PRESSED => key pointer is set
	if (this->keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
	{
		char temp_char = this->keyboard.get_pressed_key()->get_label();
		
		this->check_rotor_turnovers();

		//unnamed_char = rotor.pass_through(unnamed_char);
		//unnamed_char = reflector.swap_character(unnamed_char);
		//unnamed_char = rotor.reverse_pass_through(unnamed_char);

		lampboard.turn_on_lamp(temp_char);
	}

	if (this->keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
	{
		this->lampboard.reset_lamps();
	}
}

void Controller::check_rotor_turnovers()
{
	this->rotors.at(0).turn_rotor();		// First one _always_ turns

	for (auto& rotor : this->rotors)
	{
		// Check if rotor is at turnover position
		enigma::Log::debug("Checking rotor %d for turnover. Current char: %c, Turnover char: %c",
			&rotor - &this->rotors.at(0)+1,
			rotor.get_wiring().at(rotor.get_rotor_index()),
			rotor.get_turnover());
		if (rotor.get_wiring().at(rotor.get_rotor_index()) == rotor.get_turnover())
		{
			enigma::Log::debug("Rotor %d is at turnover position. Turning next rotor.",
				&rotor - &this->rotors.at(0)+1);
			// &rotor is just a memory address, its pointer arithmetic
			int next_rotor_index = &rotor - &this->rotors.at(0)+1;
			
			if (next_rotor_index < this->rotors.size())
			{
				this->rotors.at(next_rotor_index).turn_rotor();
				enigma::Log::debug("Rotor %d turned to index %d.",
					next_rotor_index + 1,
					this->rotors.at(next_rotor_index).get_rotor_index());
			}
		}
	}
}

void Controller::pass_through_rotors()
{
}

