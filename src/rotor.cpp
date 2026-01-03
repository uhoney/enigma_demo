#include "rotor.h"

enigma::Rotor::Rotor(std::string_view wiring, char turnover) : turnover{turnover}, rotor_wiring{wiring}
{
}

enigma::Rotor::~Rotor()
{
}

char enigma::Rotor::get_turnover() const
{
	return this->turnover;
}

char enigma::Rotor::rotor_substitute() const
{
	return this->rotor_wiring[this->position_index];
}

char enigma::Rotor::rotor_reverse_substitute() const
{
	return enigma::ALPHABETS[this->position_index];
}

int enigma::Rotor::get_position_index() const
{
	return this->position_index;
}

void enigma::Rotor::set_position_index(int new_index)
{
	this->position_index = new_index;
}

void enigma::Rotor::turn_rotor()
{
	if (this->position_index < 25)
	{
		++this->position_index;
	}
	else
	{
		this->position_index = 0;
	}
}

void enigma::Rotor::turn_back_rotor()
{
	if (this->position_index > 0)
	{
		--this->position_index;
	}
	else
	{
		this->position_index = 25;
	}
}

std::string_view enigma::Rotor::get_wiring() const
{
	return this->rotor_wiring;
}