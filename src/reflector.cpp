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
	int index = 0;
	for (auto& character : wiring)
	{
		this->reflector_array['A' + index] = character;
		index++;
	}
}

char enigma::Reflector::swap_character(const char& character)
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