#include "layout.h"

namespace ui
{
	void draw_background()
	{
		DrawRectangleRec({ CASE_OUTLINE.x, CASE_OUTLINE.y, CASE_OUTLINE.z, CASE_OUTLINE.w }, BEIGE);
		DrawRectangleRec({ CASE_INSIDE.x, CASE_INSIDE.y, CASE_INSIDE.z, CASE_INSIDE.w }, DARKGRAY);
	}

	void draw_keyboard(Font font, Vector2 font_offset, enigma::KeyBoard keyboard)
	{
		for (auto& key : keyboard.get_keys())
		{
			draw_key(font, font_offset, key);
		}
	}

	void draw_key(Font font, Vector2 font_offset, enigma::Key key)
	{
		DrawCircleV(key.get_position(), enigma::KEY_OUTER_RING, LIGHTGRAY);
		DrawCircleV(key.get_position(), enigma::KEY_INNER_RING, BLACK);
		DrawTextEx(
			font,
			key.get_text(),
			{ key.get_position().x - (font_offset.x), key.get_position().y - (font_offset.y) },
			40.0f,
			0.0f,
			RAYWHITE);
	}

	void draw_lampboard(Font font, Vector2 font_offset, enigma::Lampboard lampboard)
	{
		for (auto& lamp : lampboard.get_lamps())
		{
			draw_lamp(font, font_offset, lamp);
		}
	}

	void draw_lamp(Font font, Vector2 font_offset, enigma::Lamp lamp)
	{
		if (lamp.get_is_lit())
		{
			DrawCircleV(lamp.get_position(), enigma::LAMP_RADIUS, YELLOW);
			DrawTextEx(
				font,
				lamp.get_text(),
				{ lamp.get_position().x - font_offset.x, lamp.get_position().y - font_offset.y },
				40.0f,
				0.0f,
				BLACK);

		}
		else
		{
			DrawCircleV(lamp.get_position(), enigma::LAMP_RADIUS, BLACK);
			DrawTextEx(
				font,
				lamp.get_text(),
				{ lamp.get_position().x - font_offset.x, lamp.get_position().y - font_offset.y },
				40.0f,
				0.0f,
				GRAY);
		}
	}
}