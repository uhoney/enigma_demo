#pragma once
#include <iostream>
#include <string_view>
#include <string>
#include <assert.h>
#include "raylib.h"
#include "log.h"
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

	
	inline constexpr Vector2 ROTOR_UI_INDEX_RECT_SIZE{ 60.0f, 60.0f };

	// FIXME: Quick testing layout values, adjust as needed
	inline constexpr float ROTOR_POSITION_OFFSET_X{ 180.0f };
	inline constexpr float ROTOR_POSITION_3{ ROTOR_POSITION_OFFSET_X};
	inline constexpr float ROTOR_POSITION_2{ ROTOR_POSITION_OFFSET_X + ROTOR_POSITION_3 };
	inline constexpr float ROTOR_POSITION_1{ ROTOR_POSITION_OFFSET_X + ROTOR_POSITION_2 };
	inline constexpr float ROTOR_POSITION_Y{ 150.0f };
	

	/**
	* @brief A rotating disc that spins and substitutes characters based on its wiring and position.
	* @class Rotor
	* The actual rotor did not have an index[0], computers do.
	* Rotor 1 (right side) always spins first, and when it hits its turnover notch, it causes the next rotor to the left to spin.
	* So rotor_1 rotor_index will always be index[n+1] before any actions.
	* You take your character (i.e 'Z') which is on alphabet_index[25] and add rotor_index to it and take mod 26.
	* So you get (with rotor_index 0, char 'Z') => 1+25 = 26 mod 26 = 0. This is the index of char to output, which is 'E'. (on ROTOR_I_WIRING)
	*/
	class Rotor
	{
	private:
		/**
		* @brief The wiring configuration of the rotor as a string.
		*/
		std::string wiring{};

		/**
		* @brief The turnover character that indicates when the next rotor unlocks for rotation.
		*/
		char turnover{ };

		/**
		* @brief The current position index of the rotor (0-25). Used for GUI display and substitution calculations.
		*/
		int rotor_index{ 0 };

		/**
		* @brief The position of the rotor in the UI. Also base position for other rotor UI elements.
		*/
		Vector2 rotor_position{ };
		
	public:
		/**
		* @brief Construct a new Rotor object with specified wiring and turnover character.
		*/
		Rotor(std::string_view, char, Vector2);
		~Rotor();

		/**
		* @brief Substitute the character at the current position index using the rotor wiring.
		*/
		char pass_through(char) const;

		/**
		* @brief Reverse substitute the character at the current position index using the alphabets.
		*/
		char reverse_pass_through(char) const;

		/**
		* @brief DEBUG USE ONLY. Set the current position index of the rotor.
		*/
		void set_rotor_index(int);

		/**
		* @brief Increment the position index of the rotor, wrapping around to 0 after 25.
		* Keeps this specifically separate. You do not want to change index when passing through.
		*/
		void turn_rotor();

		/**
		* @brief Decrement the position index of the rotor, wrapping around to 25 after 0.
		*/
		void turn_back_rotor();

		/**
		* @brief Get the current position index of the rotor.
		*/
		int get_rotor_index() const;

		/**
		* @brief Get position of char in selected std::string_view
		* Basically either ALPHABETS or ROTOR_X_WIRING.
		*/
		int get_index_of_char(std::string_view, char) const;

		/**
		* @brief Get the turnover character of the rotor.
		*/
		char get_turnover_char() const;

		/**
		* @brief Get the position index of the turnover character.
		*/
		int get_turnover_index() const;

		/**
		* @brief Get the wiring of the rotor.
		*/
		std::string get_wiring() const;

		/**
		* @brief Get the position of the rotor in the UI.
		*/
		Vector2 get_rotor_position() const;
	};
}