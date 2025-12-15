#include "reflector.h"
#include <array>

Reflector::Reflector()
{
	this->initialize_UKW_A();
}

Reflector::~Reflector()
{
}

void Reflector::initialize_UKW_A()
{
	// Aakkoset	= ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// UKW-A	= EJMZALYXVBWFCRQUONTSPIKHGD

	this->reflector_array['A'] = 'E';
	this->reflector_array['B'] = 'J';
	this->reflector_array['C'] = 'M';
	this->reflector_array['D'] = 'Z';
	this->reflector_array['E'] = 'A';
	this->reflector_array['F'] = 'L';
	this->reflector_array['G'] = 'Y';
	this->reflector_array['H'] = 'X';
	this->reflector_array['I'] = 'V';
	this->reflector_array['J'] = 'B';
	this->reflector_array['K'] = 'W';
	this->reflector_array['L'] = 'F';
	this->reflector_array['M'] = 'C';
	this->reflector_array['N'] = 'R';
	this->reflector_array['O'] = 'Q';
	this->reflector_array['P'] = 'U';
	this->reflector_array['Q'] = 'O';
	this->reflector_array['R'] = 'N';
	this->reflector_array['S'] = 'T';
	this->reflector_array['T'] = 'S';
	this->reflector_array['U'] = 'P';
	this->reflector_array['V'] = 'I';
	this->reflector_array['W'] = 'K';
	this->reflector_array['X'] = 'H';
	this->reflector_array['Y'] = 'G';
	this->reflector_array['Z'] = 'D';
}

void Reflector::initialize_UKW_B()
{
	// Aakkoset	= ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// UKW_B	= YRUHQSLDPXNGOKMIEBFZCWVJAT

	this->reflector_array['A'] = 'Y';
	this->reflector_array['B'] = 'R';
	this->reflector_array['C'] = 'U';
	this->reflector_array['D'] = 'H';
	this->reflector_array['E'] = 'Q';
	this->reflector_array['F'] = 'S';
	this->reflector_array['G'] = 'L';
	this->reflector_array['H'] = 'D';
	this->reflector_array['I'] = 'P';
	this->reflector_array['J'] = 'X';
	this->reflector_array['K'] = 'N';
	this->reflector_array['L'] = 'G';
	this->reflector_array['M'] = 'O';
	this->reflector_array['N'] = 'K';
	this->reflector_array['O'] = 'M';
	this->reflector_array['P'] = 'I';
	this->reflector_array['Q'] = 'E';
	this->reflector_array['R'] = 'B';
	this->reflector_array['S'] = 'F';
	this->reflector_array['T'] = 'Z';
	this->reflector_array['U'] = 'C';
	this->reflector_array['V'] = 'W';
	this->reflector_array['W'] = 'V';
	this->reflector_array['X'] = 'J';
	this->reflector_array['Y'] = 'A';
	this->reflector_array['Z'] = 'T';
}

void Reflector::initialize_UKW_C()
{
	// Aakkoset	= ABCDEFGHIJKLMNOPQRSTUVWXYZ
	// UKW_C	= FVPJIAOYEDRZXWGCTKUQSBNMHL

	this->reflector_array['A'] = 'F';
	this->reflector_array['B'] = 'V';
	this->reflector_array['C'] = 'P';
	this->reflector_array['D'] = 'J';
	this->reflector_array['E'] = 'I';
	this->reflector_array['F'] = 'A';
	this->reflector_array['G'] = 'O';
	this->reflector_array['H'] = 'Y';
	this->reflector_array['I'] = 'E';
	this->reflector_array['J'] = 'D';
	this->reflector_array['K'] = 'R';
	this->reflector_array['L'] = 'Z';
	this->reflector_array['M'] = 'X';
	this->reflector_array['N'] = 'W';
	this->reflector_array['O'] = 'G';
	this->reflector_array['P'] = 'C';
	this->reflector_array['Q'] = 'T';
	this->reflector_array['R'] = 'K';
	this->reflector_array['S'] = 'U';
	this->reflector_array['T'] = 'Q';
	this->reflector_array['U'] = 'S';
	this->reflector_array['V'] = 'B';
	this->reflector_array['W'] = 'N';
	this->reflector_array['X'] = 'M';
	this->reflector_array['Y'] = 'H';
	this->reflector_array['Z'] = 'L';
}

char Reflector::swap_character(const char & character)
{
	if (character < 'A' || character > 'Z') {
		return '0';
	}
	
	else
	{
		return this->reflector_array[character];
	}

}
