#include "rotor.h"

enigma::Rotor::Rotor(std::string_view wiring, char turnover) : turnover{ turnover }, rotor_wiring{ wiring }
{
}

enigma::Rotor::~Rotor()
{
}

char enigma::Rotor::substitute(char input_character) const
{
	int index_of_input = this->get_index_of_char(input_character);
	int index_of_output = (index_of_input + this->rotor_index) % 26;

	return this->rotor_wiring[index_of_output];
}

char enigma::Rotor::reverse_substitute() const
{
	return enigma::ALPHABETS[this->rotor_index];
}

void enigma::Rotor::set_position_index(int new_index)
{
	this->rotor_index = new_index;
}

char enigma::Rotor::pass_through(char character)
{
	this->turn_rotor();
	
	return this->substitute(character);
}

char enigma::Rotor::reverse_pass_through(char character)
{

	return 0;
}

void enigma::Rotor::turn_rotor()
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

void enigma::Rotor::turn_back_rotor()
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

int enigma::Rotor::get_rotor_index() const
{
	return this->rotor_index;
}

int enigma::Rotor::get_index_of_char(char character) const
{
	int alphabet_position = enigma::ALPHABETS.find(character);
	if (alphabet_position != std::string_view::npos)
	{
		return alphabet_position;
	}

	return -1; // Default
}

char enigma::Rotor::get_turnover() const
{
	return this->turnover;
}

std::string_view enigma::Rotor::get_wiring() const
{
	return this->rotor_wiring;
}