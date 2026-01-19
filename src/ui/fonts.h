#pragma once

#include "raylib.h"
#include "../core/log.h"

namespace ui
{
	/// @name Font configuration constants
	/// @{
	inline constexpr const char* FONT_PATH = "assets/fonts/UbuntuMono-R.ttf"; 
	inline constexpr int FONT_SIZE = 80;
	inline constexpr int FONT_CODEPOINTS_COUNT = 0;
	/// @}

	/**
	* Initializes and returns a font object used in the UI. If loading fails, logs an error and returns the default font.
	*/
	Font load_font();
}