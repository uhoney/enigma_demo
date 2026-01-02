#include "rotor.h"
#include "rotor.h"

enigma::Rotor::Rotor(std::string_view& wiring, char notch) :
	turnover{ notch }, current_position{ wiring[0] }
{
	int index = 0;
	for (auto& character : wiring)
	{
		this->reflector_array['A' + index] = character;
		++index;
	}
}

enigma::Rotor::~Rotor()
{
}

char enigma::Rotor::get_turnover() const
{
	return this->turnover;
}

char enigma::Rotor::get_current_position() const
{
	return this->current_position;
}

void enigma::Rotor::turn_rotor()
{
	++this->current_position;
}
