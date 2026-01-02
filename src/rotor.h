#pragma once
#include <string_view>
#include <array>
#include "constants.h"

namespace enigma
{
	/**
	 * @class Rotor
	 * Represents a rotor in the Enigma machine, responsible for character substitution based on its wiring and position.
	 */
	class Rotor
	{
	private:
		 /**
		  * @brief The wiring configuration of the rotor as a string view.
		  */
		std::string_view rotor_wiring{};
		/**
		 * @brief The turnover character that indicates when the next rotor unlocks for rotation.
		 */
		char turnover{};
		/**
		 * @brief The current position index of the rotor (0-25). Used for GUI display and substitution calculations.
		 */
		int position_index{0};

	public:
		Rotor(std::string_view, char );
		~Rotor();

		/**
		 * @brief Get the turnover character of the rotor.
		 */
		char get_turnover() const;

		/**
		 * @brief Substitute the character at the current position index using the rotor wiring.
		 */
		char rotor_substitute() const;

		/**
		 * @brief Reverse substitute the character at the current position index using the alphabets.
		 */
		char rotor_reverse_substitute() const;

		/**
		 * @brief Get the current position index of the rotor.
		 */
		int get_position_index() const;

		void set_position_index(int); // TODO: DEBUG ONLY, delete later

		/**
		 * @brief Increment the position index of the rotor, wrapping around to 0 after 25.
		 */
		void add_position_index();

		/**
		 * @brief Decrement the position index of the rotor, wrapping around to 25 after 0.
		 */
		void substract_position_index();

		/**
		 * @brief Get the wiring of the rotor.
		 */
		std::string_view get_wiring() const;
	};
}