#include "reflector.h"
#include <array>

namespace enigma
{
	Reflector::Reflector() : reflector_wiring{ UKW_A_WIRING }
	{
	}

	Reflector::~Reflector()
	{
	}

	void Reflector::initialize_UKW(std::string_view wiring)
	{
		this->reflector_wiring = wiring;
	}

	int Reflector::get_index_from_char(char character_input)
	{
		auto index = std::find(ALPHABETS.begin(), ALPHABETS.end(), character_input);

		if (index != ALPHABETS.end())
		{
			return static_cast<int>(std::distance(ALPHABETS.begin(), index));
		}
		else
		{
			return 0;	// default to 0 to shut up compiler warning
		}
	}

	char Reflector::swap_character(char character)
	{
		TraceLog(LOG_DEBUG, "Reflector input character: %c", character);
		TraceLog(LOG_DEBUG, "Reflector output character: %c", this->reflector_wiring[get_index_from_char(character)]);
		return this->reflector_wiring[get_index_from_char(character)];
	}
}