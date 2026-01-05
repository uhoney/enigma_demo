#include "raylib.h"
#include "rotor.h"
#include <iostream>

namespace enigma
{
	Rotor::Rotor(std::string_view wiring, char turnover) : turnover{ turnover }, rotor_wiring{ wiring }
	{
	}

	Rotor::~Rotor()
	{
	}

	char Rotor::pass_through(char input_character) const
	{
		TraceLog(LOG_DEBUG, "Rotor pass through called with input character: %c", input_character);
		int index_of_input = this->get_index_of_char(ALPHABETS, input_character);
		int index_of_output = (index_of_input + this->rotor_index) % 26;
		TraceLog(LOG_DEBUG, "Rotor output: %c", this->rotor_wiring[index_of_output]);

		return this->rotor_wiring[index_of_output];
	}

	char Rotor::reverse_pass_through(char input_character) const
	{
		int index_of_input = this->get_index_of_char(this->get_wiring(), input_character);
		int index_of_output = (index_of_input - this->rotor_index + 26) % 26;

		return enigma::ALPHABETS[index_of_output];
	}

	void Rotor::set_position_index(int new_index)
	{
		if (new_index < 0 || new_index > 25)
		{
			// FIXME: Proper error handling missing
			std::cerr << "Error: Rotor index out of bounds. Must be between 0 and 25.\n";
			this->rotor_index = 0;
			return;
		}

		this->rotor_index = new_index;
	}

	void Rotor::turn_rotor()
	{
		if (this->rotor_index < 25)
		{
			++this->rotor_index;
		}
		else
		{
			this->rotor_index = 0;
		}
	}

	void Rotor::turn_back_rotor()
	{
		if (this->rotor_index > 0)
		{
			--this->rotor_index;
		}
		else
		{
			this->rotor_index = 25;
		}
	}

	int Rotor::get_rotor_index() const
	{
		return this->rotor_index;
	}

	int Rotor::get_index_of_char(std::string_view stringview, char character) const
	{
		int character_position = stringview.find(character);
		if (character_position != std::string_view::npos)
		{
			return character_position;
		}

		// TODO: Figure out error handling later, now shut up compiler. 
		// User can not input chars anyway, but just in case.
		return -1;

	}

	char Rotor::get_turnover() const
	{
		return this->turnover;
	}

	std::string_view Rotor::get_wiring() const
	{
		return this->rotor_wiring;
	}
}