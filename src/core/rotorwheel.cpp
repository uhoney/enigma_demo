#include "rotorwheel.h"
#include "rotorwheel.h"

namespace enigma
{
	RotorWheel::RotorWheel()
	{
		// NOTE: brace initialization looked horrible and unreadable
		this->rotorwheels.reserve(3);
		rotorwheels.emplace_back(Rotor{ ROTOR_I_WIRING, ROTOR_I_TURNOVER });
		rotorwheels.emplace_back(Rotor{ ROTOR_II_WIRING, ROTOR_II_TURNOVER });
		rotorwheels.emplace_back(Rotor{ ROTOR_III_WIRING, ROTOR_III_TURNOVER });
	}

	RotorWheel::~RotorWheel()
	{
	}


	std::vector<Rotor> RotorWheel::get_rotorwheels()
	{
		return this->rotorwheels;
	}

	char enigma::RotorWheel::run_through_rotors(char input_character)
	{
		this->rotorwheels.at(0).turn_rotor();
		TraceLog(LOG_DEBUG, "Rotor 1 at index %d", this->rotorwheels.at(0).get_rotor_index());
		// if rotor 1 is at turnover, turn rotor 2
		// if rotor 2 is at turnover, turn rotor 3
		
		char temp_char{ this->rotorwheels.at(0).pass_through(input_character) };
		temp_char = this->rotorwheels.at(1).pass_through(temp_char);
		temp_char = this->rotorwheels.at(2).pass_through(temp_char);
		
		return temp_char;
	}

	char RotorWheel::reverse_run_through_rotors(char input_character)
	{
		return 0;
	}

}