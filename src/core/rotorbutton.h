#pragma once

#include "raylib.h"

namespace enigma
{
	/// @name Rotor button constants
	/// @{
	inline constexpr float ROTOR_BUTTON_OFFSET_X{ 60.0f };
	inline constexpr float ROTOR_BUTTON_OFFSET_Y{ 60.0f };
	inline constexpr Vector2 ROTOR_BUTTON_SIZE{ 60.0f, 60.0f };
	/// @}

	/**
	* UI button for turning rotors manually.
	*/
	class RotorButton
	{
	private:
		Vector2 position{};

	public:
		RotorButton();
		~RotorButton();

		void set_button_position(Vector2);
		
		Vector2 get_button_position();

	};


}