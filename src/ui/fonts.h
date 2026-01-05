#pragma once

#include "raylib.h"

namespace ui
{
	inline constexpr const char* FONT_PATH = "assets/fonts/UbuntuMono-R.ttf";
	inline constexpr int FONT_SIZE = 80;
	inline constexpr int FONT_CODEPOINTS_COUNT = 0;
	inline constexpr Vector2 FONT_OFFSET{ 10.0f, 20.0f };

	Font load_font();
}