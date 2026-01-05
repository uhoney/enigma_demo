#include "lampboard.h"

namespace enigma
{
	Lampboard::Lampboard()
	{
		float temp_x{ LAMPBOARD_POSITION_X };
		float temp_y{ LAMPBOARD_POSITION_Y };

		for (char character : ENIGMA_KEYBOARD_CHARACTERS)
		{
			if (character == 'A')
			{
				temp_x = LAMPBOARD_POSITION_X + 25.0f;
				temp_y = LAMPBOARD_POSITION_Y + 75.0f;
			}
			else if (character == 'P')
			{
				temp_x = LAMPBOARD_POSITION_X;
				temp_y += 75.0f;
			}

			this->lamps.emplace_back(character, Vector2{ temp_x, temp_y });
			temp_x += LAMP_PADDING;
		}
	}

	Lampboard::~Lampboard()
	{
	}

	std::vector<Lamp>& Lampboard::get_lamps()
	{
		return this->lamps;
	}

	void Lampboard::turn_on_lamp(char lamp_character)
	{
		for (auto& lamp : this->lamps)
		{
			if (lamp.get_label() == lamp_character)
			{
				if (!lamp.get_is_lit())
				{
					lamp.toggle_lamp();
				}
				break;
			}
		}
	}

	void Lampboard::reset_lamps()
	{
		for (auto& lamp : this->lamps)
		{
			if (lamp.get_is_lit())
			{
				lamp.toggle_lamp();
			}
		}
	}
}