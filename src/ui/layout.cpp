#include "layout.h"

namespace ui
{
	void draw_background()
	{
		DrawRectangleRec({ CASE_OUTLINE.x, CASE_OUTLINE.y, CASE_OUTLINE.z, CASE_OUTLINE.w }, BEIGE);
		DrawRectangleRec({ CASE_INSIDE.x, CASE_INSIDE.y, CASE_INSIDE.z, CASE_INSIDE.w }, DARKGRAY);
	}

	void draw_keyboard(Font font, enigma::Keyboard keyboard)
	{
		for (auto& key : keyboard.get_keys())
		{
			draw_key(font, key);
		}
	}

	void draw_key(Font font, enigma::Key key)
	{
		DrawCircleV(key.get_position(), enigma::KEY_OUTER_RING * key.get_size_multiplier(), LIGHTGRAY);
		DrawCircleV(key.get_position(), enigma::KEY_INNER_RING * key.get_size_multiplier(), BLACK);
		DrawTextEx(
			font,
			key.get_text(),
			{ key.get_position().x - enigma::KEY_FONT_OFFSET.x * key.get_size_multiplier(), key.get_position().y - enigma::KEY_FONT_OFFSET.y * key.get_size_multiplier() },
			enigma::KEY_FONT_SIZE * key.get_size_multiplier(),
			0.0f,
			RAYWHITE);
	}

	void draw_lampboard(Font font, enigma::Lampboard lampboard)
	{
		for (auto& lamp : lampboard.get_lamps())
		{
			draw_lamp(font, lamp);
		}
	}

	void draw_lamp(Font font, enigma::Lamp lamp)
	{
		if (lamp.get_is_lit())
		{
			DrawCircleV(lamp.get_position(), enigma::LAMP_RADIUS, YELLOW);
			DrawTextEx(
				font,
				lamp.get_text(),
				{ lamp.get_position().x - enigma::LAMP_FONT_OFFSET.x, lamp.get_position().y - enigma::LAMP_FONT_OFFSET.y },
				enigma::LAMP_FONT_SIZE,
				0.0f,
				BLACK);

		}
		else
		{
			DrawCircleV(lamp.get_position(), enigma::LAMP_RADIUS, BLACK);
			DrawTextEx(
				font,
				lamp.get_text(),
				{ lamp.get_position().x - enigma::LAMP_FONT_OFFSET.x, lamp.get_position().y - enigma::LAMP_FONT_OFFSET.y },
				enigma::LAMP_FONT_SIZE,
				0.0f,
				DARKGRAY);
		}
	}
}