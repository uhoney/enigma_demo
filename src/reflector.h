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
	* 
	* Predefined array representing the wiring of the reflector, mapping each character to its corresponding index.
	* I.e 'A' maps to index 65 in ASCII.
	*/
	std::array<char, 91> reflector_array{ {} };

public:

	/**
	* Constructor initialization uses UKW_A wiring by default.
	*/ 
	Reflector();
	~Reflector();

	/**
	 * @brief Initializes the reflector with UKW_A wiring pattern.
	 * 
	 * UKW_A wiring: EJMZALYXVBWFCRQUONTSPIKHGD
	 */
	void initialize_UKW_A();
	
	/**
	 * @brief Initializes the reflector with UKW_B wiring pattern.
	 * 
	 * UKW_B wiring: YRUHQSLDPXNGOKMIEBFZCWVJAT
	 */
	void initialize_UKW_B();
	
	/**
	 * @brief Initializes the reflector with UKW_C wiring pattern.
	 * 
	 * UKW_C wiring: FVPJIAOYEDRZXWGCTKUQSBNMHL
	 */
	void initialize_UKW_C();
	
	/**
	* @brief Returns the swapped character for a given input character.
	*
	* Returns a character according to the current reflector configuration.
	* @param character The input character to swap
	*/
	char swap_character(const char& character);
};