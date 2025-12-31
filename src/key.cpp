#include "key.h"

Key::Key(char character, Vector2 position) :
	character{ character, '\0' },
	position{ position }
{
}

Key::~Key()
{
}

std::vector<Key> Key::create_all_keys(float x, float y, std::string_view keyboard_characters)
{
	std::vector<Key> buttons;
	float temp_x{ x };
	float temp_y{ y };

	// keyboard_characters == "QWERTZUIOASDFGHJKPYXCVBNML"

	// FIXME: Does what it's supposed to do. Human readable, but ugly.
	for (char character : keyboard_characters)
	{
		if (character == 'A')
		{
			temp_x = x + 25.0f;
			temp_y = y + 75.0f;
		}
		else if (character == 'P')
		{
			temp_x = x;
			temp_y += 75.0f;
		}

		buttons.emplace_back(character, Vector2{ temp_x, temp_y });
		temp_x += KEY_PADDING;

	}
	return buttons;
}

char Key::get_label() const
{
	return this->character[0];		// null terminate '/0' included in this->character
}

const char* Key::get_text()
{
	// for raylib DrawTextEx()
	// TODO: Check if you can magically get rid of this helper
	return this->character;
}

Vector2 Key::get_position() const
{
	return this->position;
}

float Key::get_key_size() const
{
	return this->outer_ring;
}

void Key::set_size_multiplier(float new_size_multiplier)
{
	this->size_multiplier = new_size_multiplier;
}

void Key::draw_key(Font font, Vector2 font_offset)
{
	DrawCircleV({ this->position }, this->size_multiplier * this->outer_ring, LIGHTGRAY);
	DrawCircleV({ this->position }, this->size_multiplier * this->inner_ring, BLACK);
	DrawTextEx(
		font,
		this->get_text(),
		{ this->position.x - (font_offset.x * this->size_multiplier), this->position.y - (font_offset.y * this->size_multiplier) },
		this->size_multiplier * 40.0f,
		0.0f,
		RAYWHITE);
}