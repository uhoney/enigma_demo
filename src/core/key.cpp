#include "key.h"

namespace enigma
{
	Key::Key(char character, const Vector2& position) :
		character{ character},
		position{ position }
	{
	}

	Key::~Key()
	{
	}

	char Key::get_label() const
	{
		return this->character;
	}

	const Vector2& Key::get_position() const
	{
		return this->position;
	}

	void Key::set_size_multiplier(float new_size_multiplier)
	{
		this->size_multiplier = new_size_multiplier;
	}

	float Key::get_size_multiplier() const
	{
		return this->size_multiplier;
	}
}
