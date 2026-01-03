#pragma once
#include <string_view>
#include <array>
#include "constants.h"

namespace enigma
{
	/**
	* @class Rotor
	* Represents a rotor in the Enigma machine, responsible for character substitution based on its wiring and position.
	*
	* Notes: the actual rotor did not have an index[0], computers do.
	* Rotor always spins first, so rotor_index will always be index[n+1] before any actions.
	* You take your character (i.e 'Z') which is on alphabet_index[25] and add rotor_index to it and take mod 26.
	* so you get (with rotor_index 0, char 'Z') 1+25 = 26 mod 26 = 0. This is the index of char to output, which is 'E'.
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
		int rotor_index{ 0 };

	public:
		Rotor(std::string_view, char);
		~Rotor();

		/**
 * @brief Substitute the character at the current position index using the rotor wiring.
 */
		char substitute(char) const;

		/**
		 * @brief Reverse substitute the character at the current position index using the alphabets.
		 */
		char reverse_substitute() const;

		void set_position_index(int); // TODO: DEBUG ONLY, delete later

		/**
		* @brief Pass a character through the rotor, incrementing the rotor position and outputs substituted character.
		* Use this when going towards reflector.
		*/
		char pass_through(char);

		/*
		* @brief Pass a character back through the rotor in reverse direction, outputting the reverse substituted character.
		* Use this when returning from reflector.
		*/
		char reverse_pass_through(char);

		/**
		 * @brief Increment the position index of the rotor, wrapping around to 0 after 25.
		 */
		void turn_rotor();

		/**
		 * @brief Decrement the position index of the rotor, wrapping around to 25 after 0.
		 */
		void turn_back_rotor();

		int get_rotor_index() const;
		/**
		 * @brief Get position of char in selected std::string_view
		 * Basically either ALPHABETS or ROTOR_X_WIRING
		 */
		int get_index_of_char(char) const;

		/**
		 * @brief Get the turnover character of the rotor.
		 */
		char get_turnover() const;

		/**
		 * @brief Get the wiring of the rotor.
		 */
		std::string_view get_wiring() const;
	};
}