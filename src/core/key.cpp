#include "key.h"
#include "key.h"

namespace enigma
{
	Key::Key(char character, Vector2 position) :
		character{ character, '\0' },
		position{ position }
	{
	}

	Key::~Key()
	{
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

	void Key::set_size_multiplier(float new_size_multiplier)
	{
		this->size_multiplier = new_size_multiplier;
	}
}
