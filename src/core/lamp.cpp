#include "lamp.h"

namespace enigma
{
	Lamp::Lamp(char character, const Vector2 position) :
		character{ character, '\0' }, position{ position }
	{
	}

	Lamp::~Lamp()
	{
	}

	char Lamp::get_label() const
	{
		return this->character[0];
	}

	const char* Lamp::get_text()
	{
		return this->character;
	}

	bool Lamp::get_is_lit() const
	{
		return this->is_lit;
	}

	Vector2 Lamp::get_position() const
	{
		return this->position;
	}

	void Lamp::toggle_lamp()
	{
		this->is_lit = !this->is_lit;
	}
}