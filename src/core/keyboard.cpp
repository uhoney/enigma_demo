#include "keyboard.h"

namespace enigma
{
	KeyBoard::KeyBoard()
	{
		float temp_x{ KEYBOARD_POSITION_X };
		float temp_y{ KEYBOARD_POSITION_Y };

		for (char character : ENIGMA_KEYBOARD_CHARACTERS)
		{
			if (character == 'A')
			{
				temp_x = KEYBOARD_POSITION_X + ROW_OFFSET_H;
				temp_y = KEYBOARD_POSITION_Y + ROW_OFFSET_V;
			}
			else if (character == 'P')
			{
				temp_x = KEYBOARD_POSITION_X;
				temp_y += ROW_OFFSET_V;
			}

			this->keys.emplace_back(character, Vector2{ temp_x, temp_y });
			temp_x += KEY_PADDING;
		}
	}

	KeyBoard::~KeyBoard()
	{
		this->p_key_pressed = nullptr;
	}

	std::vector<Key>& KeyBoard::get_keys()
	{
		return this->keys;
	}

	bool KeyBoard::isKeyPressed(Vector2& mouse_position, bool is_mouse_pressed)
	{
		if (is_mouse_pressed && this->p_key_pressed == nullptr)
		{
			for (auto& key : this->keys)
			{
				if (CheckCollisionPointCircle(mouse_position, key.get_position(), KEY_OUTER_RING))
				{
					TraceLog(LOG_DEBUG, "Key %c pressed!", key.get_label());
					this->p_key_pressed = &key;
					this->p_key_pressed->set_size_multiplier(0.8f);
					return true;
				}
			}
		}
		return false;
	}

	bool KeyBoard::isKeyReleased(bool is_mouse_released)
	{
		if (is_mouse_released && this->p_key_pressed != nullptr)
		{
			this->p_key_pressed->set_size_multiplier(1.0f);
			this->p_key_pressed = nullptr;
			return true;
		}
		return false;
	}

	Key* KeyBoard::get_p_pressed_key()
	{
		return this->p_key_pressed;
	}
}