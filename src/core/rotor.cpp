#include "rotor.h"

namespace enigma
{
	Rotor::Rotor(std::string_view wiring, char turnover, Vector2 position) :
		wiring{ wiring }, turnover{ turnover }, rotor_position{ position }
	{
	}

	Rotor::~Rotor()
	{
	}

	char Rotor::pass_through(char input_character) const
	{
		enigma::Log::debug("Rotor pass through called with input character: %c", input_character);
		int index_of_input = this->get_index_of_char(enigma::ALPHABETS, input_character);
		int index_of_output = (index_of_input + this->rotor_index) % 26;
		enigma::Log::debug("Rotor output: %c", this->wiring[index_of_output]);

		return this->wiring[index_of_output];
	}

	char Rotor::reverse_pass_through(char input_character) const
	{
		enigma::Log::debug("Rotor reverse pass through called with input character: %c", input_character);
		int index_of_input = this->get_index_of_char(this->get_wiring(), input_character);
		int index_of_output = (index_of_input - this->rotor_index + 26) % 26;
		enigma::Log::debug("Rotor reverse output: %c", enigma::ALPHABETS[index_of_output]);

		return enigma::ALPHABETS[index_of_output];
	}

	void Rotor::set_rotor_index(int new_index)
	{
		if (new_index < 0 || new_index > 25)
		{
			enigma::Log::error("Error: Rotor index out of bounds. Must be between 0 and 25.");
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
				
		if (character_position != std::string::npos)
		{
			return character_position;
		}

		// Should be impossible to reach this point, since user can not insert chars.
		assert(false && "Invalid character lookup in Rotor::get_index_of_char");
	}

	char Rotor::get_turnover_char() const
	{
		return this->turnover;
	}

	int Rotor::get_turnover_index() const
	{
		return this->get_index_of_char(this->wiring, this->turnover);
	}

	std::string Rotor::get_wiring() const
	{
		return this->wiring;
	}

	Vector2 enigma::Rotor::get_rotor_position() const
	{
		return this->rotor_position;
	}
}