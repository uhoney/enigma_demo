#pragma once
#include "raylib.h"

namespace ui
{
	inline constexpr int SCREEN_WIDTH = 1080;
	inline constexpr int SCREEN_HEIGHT = 800;

	inline constexpr Vector4 CASE_OUTLINE{ 150, 25, 800, 650 };
	inline constexpr Vector4 CASE_INSIDE{ 175, 50, 750, 600 };

	void draw_background();
}