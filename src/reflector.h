#pragma once
#include <array>
#include <string_view>

namespace enigma
{
	/**
	 * @brief Represents a reflector component used in an Enigma machine cipher system, which swaps input characters according to a configured wiring pattern.
	 */
	class Reflector
	{
	private:
		/**
		 * @brief
		 * Predefined array representing the wiring of the reflector, mapping each character to its corresponding index.
		 * I.e 'A' maps to index 65 in UTF-8, so the reflector_array[65] gives the character that 'A' is mapped to.
		 */
		std::array<char, 91> reflector_array{ {} };
		/**
		 * @name UKW Wiring Configurations
		 * just string views for different reflector wirings
		 * @{
		 */
		static constexpr std::string_view UKW_A_WIRING = "EJMZALYXVBWFCRQUONTSPIKHGD";
		static constexpr std::string_view UKW_B_WIRING = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
		static constexpr std::string_view UKW_C_WIRING = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
		/** @} */

	public:
		/**
		 * @brief
		 * Constructor initialization uses UKW_A wiring by default.
		 */
		Reflector();
		~Reflector();

		/**
		 * @brief Reflector wiring initialization
		 * Initializes the reflector wiring based on the provided wiring string.
		 * UKW_A wiring: "EJMZALYXVBWFCRQUONTSPIKHGD"
		 * UKW_B wiring: "YRUHQSLDPXNGOKMIEBFZCWVJAT"
		 * UKW_C wiring: "FVPJIAOYEDRZXWGCTKUQSBNMHL"
		 */
		void initialize_UKW(std::string_view);

		/**
		 * @brief Returns the swapped character for a given input character.
		 * Returns a character according to the current reflector configuration.
		 * @param character The input character to swap
		 */
		char swap_character(const char& character);

		/**
		 * @name Getter functions for UKW wiring configurations
		 * @{
		 */
		std::string_view get_UKW_A_WIRING();
		std::string_view get_UKW_B_WIRING();
		std::string_view get_UKW_C_WIRING();
		/** @} */
	};
} // namespace enigma