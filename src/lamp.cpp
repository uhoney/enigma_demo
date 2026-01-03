#include "lamp.h"

namespace enigma
{
	enigma::Lamp::Lamp(char character, const Vector2 position) :
		character{ character, '\0' }, position{ position }
	{

	}

	enigma::Lamp::~Lamp()
	{
	}

	char Lamp::get_label() const
	{
		return this->character[0];
	}

	const char* enigma::Lamp::get_text()
	{
		return this->character;
	}

	void Lamp::draw_lamp(Font font, Vector2 font_offset)
	{
		if (this->is_lit)
		{
			DrawCircleV({ this->position }, enigma::LAMP_RADIUS, YELLOW);
			DrawTextEx(
				font,
				this->get_text(),
				{ this->position.x - font_offset.x, this->position.y - font_offset.y },
				40.0f,
				0.0f,
				BLACK);
		}
		else
		{
			DrawCircleV({ this->position }, enigma::LAMP_RADIUS, BLACK);
			DrawTextEx(
				font,
				this->get_text(),
				{ this->position.x - font_offset.x, this->position.y - font_offset.y },
				40.0f,
				0.0f,
				GRAY);
		}
		
	}

	bool Lamp::get_is_lit() const
	{
		return this->is_lit;
	}

	void Lamp::toggle_lamp()
	{
		this->is_lit = !this->is_lit;
	}
}