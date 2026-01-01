#include "reflector.h"
#include <array>

enigma::Reflector::Reflector()
{
	this->initialize_UKW(UKW_A_WIRING);
}

enigma::Reflector::~Reflector()
{
}

void enigma::Reflector::initialize_UKW(std::string_view wiring)
{
	// Alphabet:		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	// UKW_A wiring:	"EJMZALYXVBWFCRQUONTSPIKHGD"
	for (auto &character : wiring)
	{
		// 'A' maps to index 65 in UTF-8
		// .data() gives pointer to first character in string view
		// &character - wiring.data() gives the index of the current character in the wiring
		this->reflector_array['A' + (&character - wiring.data())] = character;
		// 'A' = 65, &character = 69, wiring.data() = 65 wtf
	}
}

char enigma::Reflector::swap_character(const char &character)
{
	if (character < 'A' || character > 'Z')
	{
		return '0';
	}

	else
	{
		return this->reflector_array[character];
	}
}
std::string_view enigma::Reflector::get_UKW_A_WIRING()
{
	return this->UKW_A_WIRING;
}

std::string_view enigma::Reflector::get_UKW_B_WIRING()
{
	return this->UKW_B_WIRING;
}

std::string_view enigma::Reflector::get_UKW_C_WIRING()
{
	return this->UKW_C_WIRING;
}