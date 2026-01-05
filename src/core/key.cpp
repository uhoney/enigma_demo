#include "key.h"

enigma::Key::Key(char character, Vector2 position) :
	character{ character, '\0' },
	position{ position }
{
}

enigma::Key::~Key()
{
}

char enigma::Key::get_label() const
{
	return this->character[0];		// null terminate '/0' included in this->character
}

const char* enigma::Key::get_text()
{
	// for raylib DrawTextEx()
	// TODO: Check if you can magically get rid of this helper
	return this->character;
}

Vector2 enigma::Key::get_position() const
{
	return this->position;
}

float enigma::Key::get_key_size() const
{
	return enigma::KEY_OUTER_RING;
}

void enigma::Key::set_size_multiplier(float new_size_multiplier)
{
	this->size_multiplier = new_size_multiplier;
}

void enigma::Key::draw_key(Font font, Vector2 font_offset)
{
	DrawCircleV({ this->position }, this->size_multiplier * enigma::KEY_OUTER_RING, LIGHTGRAY);
	DrawCircleV({ this->position }, this->size_multiplier * enigma::KEY_INNER_RING, BLACK);
	DrawTextEx(
		font,
		this->get_text(),
		{ this->position.x - (font_offset.x * this->size_multiplier), this->position.y - (font_offset.y * this->size_multiplier) },
		this->size_multiplier * 40.0f,
		0.0f,
		RAYWHITE);
}
