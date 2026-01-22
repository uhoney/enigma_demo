#pragma once
#include <iostream>
#include <string_view>
#include <string>
#include <assert.h>
#include "raylib.h"
#include "log.h"
#include "../constants.h"
#include "rotorbutton.h"

namespace enigma
{
	/// @name Rotor constants
	/// @{
	inline constexpr std::string_view ROTOR_I_WIRING = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	inline constexpr char ROTOR_I_TURNOVER = 'Q';
	inline constexpr std::string_view ROTOR_II_WIRING = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	inline constexpr char ROTOR_II_TURNOVER = 'E';
	inline constexpr std::string_view ROTOR_III_WIRING = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	inline constexpr char ROTOR_III_TURNOVER = 'V';
	/// @}

	/// @name Rotor UI constants
	///	@{
	inline constexpr Vector2 ROTOR_UI_INDEX_RECT_SIZE{ 60.0f, 60.0f };
	inline constexpr float ROTOR_POSITION_OFFSET_X{ 180.0f };
	inline constexpr float ROTOR_POSITION_3{ ROTOR_POSITION_OFFSET_X };
	inline constexpr float ROTOR_POSITION_2{ ROTOR_POSITION_OFFSET_X + ROTOR_POSITION_3 };
	inline constexpr float ROTOR_POSITION_1{ ROTOR_POSITION_OFFSET_X + ROTOR_POSITION_2 };
	inline constexpr float ROTOR_POSITION_Y{ 125.0f };
	/// @}

	/**
	* A rotating disc that spins and substitutes characters based on its wiring and position.
	* The actual rotor did not have an index[0], computers do.
	* Rotor 1 (right side) always spins. Depending on turnover, it may cause rotor 2 to spin, which may cause rotor 3 to spin.
	*
	* So rotor_1 rotor_index will always be index[n+1] before any actions.
	* You take your character (i.e 'Z') which is on alphabet_index[25] and add rotor_index to it and take mod 26.
	* So you get (with rotor_index 0, char 'Z') => 1+25 = 26 mod 26 = 0. This is the index of char to output, which is 'E'. (on ROTOR_I_WIRING)
	*/
	class Rotor
	{
	private:
		std::string_view wiring{};

		/**
		* The turnover character that indicates when the next rotor will be turned.
		*/
		char turnover{ };

		/**
		* The current position index of the rotor (0-25). Used for GUI display and substitution calculations.
		*/
		int rotor_index{ 0 };

		/**
		* The position of the rotor in the UI. Also base position for other rotor UI elements.
		*/
		Vector2 rotor_position{ };

		/**
		* Just to keep track of which button is currently pressed. nullptr if none.
		* 
		* Fixes issue where both buttons would register as pressed if mouse held down while over both.
		*/

		RotorButton* p_button_pressed{ nullptr };

	public:
		/**
		* UI element for rotor control.
		*/
		RotorButton button_up{};

		/**
		* UI element for rotor control.
		*/
		RotorButton button_down{};
		
		Rotor(std::string_view, char, const Vector2&);
		~Rotor();

		/**
		* Substitute the input character at the current position index using the rotor wiring.
		*/
		char pass_through(char) const;

		/**
		* Reverse substitute the input character at the current position index using the alphabets.
		*/
		char reverse_pass_through(char) const;

		/**
		* DEBUG USE ONLY. Set the current position index of the rotor.
		*/
		void set_rotor_index(int);

		/**
		* Increment the position index of the rotor, wrapping around to 0 after 25.
		*/
		void turn_rotor();

		/**
		* Decrement the position index of the rotor, wrapping around to 25 after 0.
		*/
		void turn_back_rotor();

		/**
		* Get the current position index of the rotor.
		*/
		int get_rotor_index() const;

		/**
		* Get position of char in selected std::string_view
		* Basically either ALPHABETS or ROTOR_X_WIRING.
		*/
		int get_index_of_char(std::string_view, char) const;

		/**
		* Get the turnover character of the rotor.
		*/
		char get_turnover_char() const;

		/**
		* Get the position index of the turnover character.
		*/
		int get_turnover_index() const;

		std::string_view get_wiring() const;

		/**
		* Get the position of the rotor in the UI.
		*/
		Vector2 get_rotor_position() const;

		/**
		* Checks if either (up or down) button is pressed (in this rotor).
		*/
		bool is_button_pressed(const Vector2&, const bool&);

		/**
		* Just sets p_button_pressed to nullptr if mouse released.
		*/
		void check_if_button_released(bool&);

		RotorButton* get_pressed_button();
	};
}