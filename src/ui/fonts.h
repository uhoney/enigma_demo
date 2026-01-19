#pragma once

#include "raylib.h"
#include "../core/log.h"

namespace ui
{
	inline constexpr const char* FONT_PATH = "assets/fonts/UbuntuMono-R.ttf"; 
	inline constexpr int FONT_SIZE = 80;
	inline constexpr int FONT_CODEPOINTS_COUNT = 0;

	/**
	* @brief Load UI font
	*
	* Initializes and returns a font object used in the UI.
	*/
	Font load_font();
}