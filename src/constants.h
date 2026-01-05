#pragma once
#include <string_view>
#include "raylib.h"

namespace enigma
{
	inline constexpr std::string_view ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	inline constexpr std::string_view ENIGMA_KEYBOARD_CHARACTERS{ "QWERTZUIOASDFGHJKPYXCVBNML" };
}