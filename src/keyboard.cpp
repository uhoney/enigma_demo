#include "keyboard.h"

enigma::KeyBoard::KeyBoard()
{
	float temp_x{ KEYBOARD_POSITION_X };
	float temp_y{ KEYBOARD_POSITION_Y };

	// FIXME: Does what it's supposed to do. Ugly but human readable.
	for (char character : ENIGMA_KEYBOARD_CHARACTERS)
	{
		if (character == 'A')
		{
			temp_x = KEYBOARD_POSITION_X + 25.0f;
			temp_y = KEYBOARD_POSITION_Y + 75.0f;
		}
		else if (character == 'P')
		{
			temp_x = KEYBOARD_POSITION_X;
			temp_y += 75.0f;
		}

		this->keys.emplace_back(character, Vector2{ temp_x, temp_y });
		temp_x += KEY_PADDING;
	}
}

enigma::KeyBoard::~KeyBoard()
{
	this->p_key_pressed = nullptr;
}

std::vector<enigma::Key>& enigma::KeyBoard::get_keys()
{
	return this->keys;
}

void enigma::KeyBoard::isKeyPressed(Vector2& mouse_position, bool is_mouse_pressed)
{
	if (is_mouse_pressed && this->p_key_pressed == nullptr)
	{
		for (auto& key : this->keys)
		{
			if (CheckCollisionPointCircle(mouse_position, key.get_position(), key.get_key_size()))
			{
				TraceLog(LOG_INFO, "Key %c pressed!", key.get_label());
				this->p_key_pressed = &key;
				this->p_key_pressed->set_size_multiplier(0.8f);
				break;
			}
		}
	}
}

void enigma::KeyBoard::isKeyReleased(bool is_mouse_released)
{
	if (is_mouse_released && this->p_key_pressed != nullptr)
	{
		this->p_key_pressed->set_size_multiplier(1.0f);
		this->p_key_pressed = nullptr;
	}
}

enigma::Key* enigma::KeyBoard::get_p_pressed_key()
{
	return this->p_key_pressed;
}
