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
			TextFormat("%c", key.get_label()),
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
				TextFormat("%c", lamp.get_label()),
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
				TextFormat("%c", lamp.get_label()),
				{ lamp.get_position().x - enigma::LAMP_FONT_OFFSET.x, lamp.get_position().y - enigma::LAMP_FONT_OFFSET.y },
				enigma::LAMP_FONT_SIZE,
				0.0f,
				DARKGRAY);
		}
	}

	void ui::draw_rotor_index(Font font, Vector2 rect_position, Vector2 rect_size, enigma::Rotor rotor)
	{
		// offset inside rectangle to create outline effect
		DrawRectangleV(rect_position, rect_size, BLACK);
		DrawRectangleV({ rect_position.x + 3.0f, rect_position.y + 3.0f }, { rect_size.x - 6.0f, rect_size.y - 6.0f }, RAYWHITE);

		DrawTextEx(
			font,
			TextFormat("%d", rotor.get_rotor_index() + 1), // rotors count from 0, but display from 1
			{ rect_position.x + 10.0f, rect_position.y + 8.0f },
			40.0f,
			0.0f,
			BLACK);
	}

	void ui::draw_rotor_buttons(Controller& controller)
	{
		for (size_t i = 0; i < controller.rotors.size(); ++i)
		{
			Vector2 button_up_pos{ controller.rotors.at(i).get_rotor_position().x,
								   controller.rotors.at(i).get_rotor_position().y - enigma::ROTOR_BUTTON_OFFSET_Y };

			DrawRectangleV(button_up_pos, enigma::ROTOR_BUTTON_SIZE, GRAY);

			DrawTriangle(
				{ button_up_pos.x + enigma::ROTOR_BUTTON_SIZE.x / 2.0f, button_up_pos.y + 10.0f },
				{ button_up_pos.x + 10.0f, button_up_pos.y + enigma::ROTOR_BUTTON_SIZE.y - 10.0f },
				{ button_up_pos.x + enigma::ROTOR_BUTTON_SIZE.x - 10.0f, button_up_pos.y + enigma::ROTOR_BUTTON_SIZE.y - 10.0f },
				BLACK
			);

			Vector2 button_down_pos{ controller.rotors.at(i).get_rotor_position().x,
									 controller.rotors.at(i).get_rotor_position().y + enigma::ROTOR_BUTTON_OFFSET_Y };

			DrawRectangleV(button_down_pos, enigma::ROTOR_BUTTON_SIZE, GRAY);

			DrawTriangle(
				{ button_down_pos.x + enigma::ROTOR_BUTTON_SIZE.x / 2.0f, button_down_pos.y + enigma::ROTOR_BUTTON_SIZE.y - 10.0f },
				{ button_down_pos.x + enigma::ROTOR_BUTTON_SIZE.x - 10.0f, button_down_pos.y + 10.0f },
				{ button_down_pos.x + 10.0f, button_down_pos.y + 10.0f },
				BLACK
			);

		}
	}

	void ui::draw_rotor_ui(Font font, Controller& controller)
	{
		for (size_t i = 0; i < controller.rotors.size(); ++i)
		{
			draw_rotor_index(
				font,
				controller.rotors.at(i).get_rotor_position(),
				enigma::ROTOR_UI_INDEX_RECT_SIZE,
				controller.rotors.at(i)
			);
			draw_rotor_buttons(controller);
		}
	}
}