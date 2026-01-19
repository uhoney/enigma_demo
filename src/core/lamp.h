#pragma once

#include "../constants.h"
#include <vector>
#include "raylib.h"

namespace enigma
{
	/// @name Lamp Constants
	/// @{
	inline constexpr float LAMP_RADIUS{ 30.0f };
	inline constexpr float LAMP_PADDING{ 75.0f };
	inline constexpr float LAMP_FONT_SIZE{ 40.0f };
	inline constexpr Vector2 LAMP_FONT_OFFSET{ 10.0f, 20.0f };
	/// @}

	/**
	* Each lamp corresponds to a character in the alphabet and lights up when that character is the output of the Enigma machine.
	*/
	class Lamp
	{
	private:
		char character{};
		bool is_lit{ false };
		Vector2 position{};

	public:
		Lamp(char, const Vector2);
		~Lamp();

		/**
		* Returns the character of the lamp.
		*/
		char get_label() const;
		
		bool get_is_lit() const;
		
		Vector2 get_position() const;

		void toggle_lamp();

    };
}