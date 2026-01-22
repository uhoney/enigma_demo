#pragma once
#include "log.h"
#include <array>
#include <string_view>
#include <algorithm>
#include "../constants.h"

namespace enigma
{
	/// @name Reflector constants
	/// @{
	inline constexpr std::string_view UKW_A_WIRING = "EJMZALYXVBWFCRQUONTSPIKHGD";
	inline constexpr std::string_view UKW_B_WIRING = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	inline constexpr std::string_view UKW_C_WIRING = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
	/// @}

	/**
	* A reflector component in the Enigma machine that swaps characters based on a wiring configuration.
	* Only UKW-A in use currently. Perhaps in future versions, reflectors can be swapped.
	*
	* Swaps 1:1 characters based on wiring. i.e. A->E, E->A
	*/
	class Reflector
	{
	private:
		std::string_view wiring{};

	public:
		/**
		 * Constructor initialization uses UKW_A_WIRING by default.
		 */
		Reflector();
		~Reflector();

		/**
		 * Initializes the reflector with specific wiring.
		 * Possible wirings; UKW_A, UKW_B, UKW_C
		 * 
		 * Again, user can not currently swap out reflectors.
		 */
		void initialize_reflector(std::string_view);

		/**
		 * Gets the index position of a character in the alphabet.
		 */
		int get_index_from_char(char) const;

		/**
		 * Swaps the input character according to the reflector wiring.
		 */
		char swap_character(char);

		std::string_view get_wiring() const; 
	};
}