#pragma once
#include <array>

/**
* @brief Represents a reflector component used in an Enigma machine cipher system, which swaps input characters according to a configured wiring pattern.
*/
class Reflector
{
private:
	/**
	* @brief 
	* Predefined array representing the wiring of the reflector, mapping each character to its corresponding index.
	* I.e 'A' maps to index 65 in ASCII.
	*/
	std::array<char, 91> reflector_array{ {} };

public:

	/**
	* @brief
	* Constructor initialization uses UKW_A wiring by default.
	*/ 
	Reflector();
	~Reflector();

	/**
	 * @name Reflector wiring initializations
	 */
	///@{
	void initialize_UKW_A();	///< UKW_A wiring: "EJMZALYXVBWFCRQUONTSPIKHGD"
	void initialize_UKW_B();	///< UKW_B wiring: "YRUHQSLDPXNGOKMIEBFZCWVJAT"
	void initialize_UKW_C();	///< UKW_C wiring: "FVPJIAOYEDRZXWGCTKUQSBNMHL"
	///@}
	
	/**
	* @brief Returns the swapped character for a given input character.
	* Returns a character according to the current reflector configuration.
	* @param character The input character to swap
	*/
	char swap_character(const char& character);
};