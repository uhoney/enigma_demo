#include "rotorbutton.h"

namespace enigma
{
	RotorButton::RotorButton()
	{
	}

	RotorButton::~RotorButton()
	{
	}

	void RotorButton::set_button_position(Vector2 new_position)
	{
		this->position = new_position;
	}

	Vector2 RotorButton::get_button_position()
	{
		return this->position;
	}
}