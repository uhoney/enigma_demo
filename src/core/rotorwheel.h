#pragma once
#include "rotor.h"
#include <vector>
#include <string_view>

namespace enigma
{
	class RotorWheel
	{
	private:
		std::vector<Rotor> rotorwheels;

	public:
		RotorWheel();
		~RotorWheel();

		std::vector<Rotor> get_rotorwheels();

		char run_through_rotors(char);
		char reverse_run_through_rotors(char);
	};
}