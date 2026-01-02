#include "reflector.h"
#include <array>

enigma::Reflector::Reflector() : reflector_wiring{enigma::UKW_A_WIRING}
{
}

enigma::Reflector::~Reflector()
{
}

void enigma::Reflector::initialize_UKW(std::string_view wiring)
{
	this->reflector_wiring = wiring;
}

int enigma::Reflector::get_index_from_char(char character_input)
{
	auto index = std::find(enigma::ALPHABETS.begin(), enigma::ALPHABETS.end(), character_input);

	if (index != enigma::ALPHABETS.end())
	{
		return static_cast<int>(std::distance(enigma::ALPHABETS.begin(), index));
	}
	else
	{
		return 0;	// default to 0 to shut up compiler warning
	}
}

char enigma::Reflector::swap_character(char character)
{
	return this->reflector_wiring[get_index_from_char(character)];
}