#include "m_button.h"

M_button::M_button(char character, Vector2 position) :
	character{ character, '\0' },
	position{ position }
{
}

M_button::~M_button()
{
}

std::vector<M_button> M_button::create_all_buttons(float x, float y, std::string button_characters)
{
	std::vector<M_button> buttons;
	float temp_x{ x };
	float temp_y{ y };

	// button_characters == "QWERTZUIOASDFGHJKPYXCVBNML"

	// FIXME: Does what it's supposed to do. Human readable, but ugly.
	for (char character : button_characters)
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
		temp_x += BUTTON_PADDING;

	}
	return buttons;
}

char M_button::get_label() const
{
	return this->character[0];		// null terminate '/0' included in this->character
}

const char* M_button::get_text()
{
	// for raylib DrawTextEx()
	// TODO: Check if you can magically get rid of this helper
	return this->character;
}

Vector2 M_button::get_position() const
{
	return this->position;
}

float M_button::get_button_size() const
{
	return this->outer_ring;
}

void M_button::set_size_multiplier(float new_size_multiplier)
{
	this->size_multiplier = new_size_multiplier;
}

void M_button::draw_button(Font font, Vector2 font_offset)
{
	DrawCircleV({ this->position }, this->size_multiplier * this->outer_ring, LIGHTGRAY);
	DrawCircleV({ this->position }, this->size_multiplier * this->inner_ring, BLACK);
	DrawTextEx(
		font,
		this->get_text(),	// takes in const char pointer
		{ this->position.x - (font_offset.x * this->size_multiplier), this->position.y - (font_offset.y * this->size_multiplier) },
		this->size_multiplier * 40.0f,
		0.0f,
		RAYWHITE);
}