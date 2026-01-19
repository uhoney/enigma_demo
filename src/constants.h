#pragma once
#include <string_view>
#include "raylib.h"

inline constexpr int SCREEN_WIDTH{ 800 };
inline constexpr int SCREEN_HEIGHT{ 800 };

namespace enigma
{
	/// @name Constants for alphabets and keyboard characters
	/// @{
	inline constexpr std::string_view ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	inline constexpr std::string_view ENIGMA_KEYBOARD_CHARACTERS{ "QWERTZUIOASDFGHJKPYXCVBNML" };
	/// @}
}