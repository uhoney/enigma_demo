#pragma once

#include "raylib.h"

namespace ui
{
	inline constexpr const char* FONT_PATH = "assets/fonts/UbuntuMono-R.ttf";
	inline constexpr int FONT_SIZE = 80;
	inline constexpr int FONT_CODEPOINTS_COUNT = 0;

	Font load_font();
}