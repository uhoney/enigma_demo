#pragma once
#include <string_view>
#include "log.h"
#include <array>
#include "../constants.h"

namespace enigma
{
	/**
	 * @name Rotor wiring configurations and corresponding turnover notches
	 * @{
	 */
	inline constexpr std::string_view ROTOR_I_WIRING = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	inline constexpr char ROTOR_I_TURNOVER = 'Q';
	inline constexpr std::string_view ROTOR_II_WIRING = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	inline constexpr char ROTOR_II_TURNOVER = 'E';
	inline constexpr std::string_view ROTOR_III_WIRING = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	inline constexpr char ROTOR_III_TURNOVER = 'V';
	/** @} */

	/**
	* @brief Represents a rotor in the Enigma machine, responsible for character substitution based on its wiring and position.
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
		/**
		* @brief Construct a new Rotor object with specified wiring and turnover character.
		*/
		Rotor(std::string_view, char);
		~Rotor();

		/**
		* @brief Substitute the character at the current position index using the rotor wiring.
		*/
		char pass_through(char) const;

		/**
		 * @brief Reverse substitute the character at the current position index using the alphabets.
		 */
		char reverse_pass_through(char) const;

		void set_position_index(int); // TODO: DEBUG ONLY, delete later
				
		/**
		 * @brief Increment the position index of the rotor, wrapping around to 0 after 25.
		 * Keeps this specifically separate. You do not want to change index when passing through.
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
		int get_index_of_char(std::string_view, char) const;

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