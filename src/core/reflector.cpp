#include "reflector.h"
#include <array>

namespace enigma
{
	Reflector::Reflector() : wiring{ UKW_A_WIRING }
	{
	}

	Reflector::~Reflector()
	{
	}

	void Reflector::initialize_reflector(std::string_view wiring)
	{
		this->wiring = wiring;
	}

	int Reflector::get_index_from_char(char character_input) const
	{
		int character_position = enigma::ALPHABETS.find(character_input);
		if (character_position != std::string::npos)
		{
			return character_position;
		}

		// TODO: Figure out error handling later, now shut up compiler.  User can not input chars anyway, but just in case.
		return -1;
	}

	char Reflector::swap_character(char character)
	{
		enigma::Log::debug("Reflector called with input character: %c", character);
		enigma::Log::debug("Reflector output: %c", this->wiring[get_index_from_char(character)]);
		return this->wiring[get_index_from_char(character)];
	}

	std::string Reflector::get_wiring()
	{
		return this->wiring;
	}
}