#pragma once
#include <array>
#include <string_view>
#include <algorithm>
#include "constants.h"

namespace enigma
{
	/**
	 * @class Reflector
	 * Represents a reflector component used in an Enigma machine cipher system, which swaps input characters according to a configured wiring pattern.
	 */
	class Reflector
	{
	private:
		std::string_view reflector_wiring{};

	public:
		/**
		 * @brief
		 * Constructor initialization uses UKW_A_WIRING by default.
		 */
		Reflector();
		~Reflector();

		/**
		 * @brief Initializes the reflector with specific wiring.
		 * Possible wirings; UKW_A, UKW_B, UKW_C
		 * @param wiring A string_view representing the wiring pattern for the reflector.
		 */
		void initialize_UKW(std::string_view);
		/**
		 * @brief Gets the index of a character in the alphabet.
		 */
		int get_index_from_char(char);
		/**
		 * @brief Swaps the input character according to the reflector wiring.
		 * @param character The input character to be swapped.
		 */
		char swap_character(char);
	};
} // namespace enigma