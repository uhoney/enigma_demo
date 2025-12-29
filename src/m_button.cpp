#include "m_button.h"

M_button::M_button(char & character, Vector2 pos)
{
	this->character = character;
	this->char_for_GUI = &character;
	this-> position = pos;
}

M_button::~M_button()
{
}

std::vector<M_button> M_button::create_all_buttons()
{
	std::vector<M_button> buttons;
	float x = 50.0f;
	float y = 50.0f;

	for (char c = 'A'; c <= 'D'; ++c)
	{
		buttons.emplace_back(M_button(c, Vector2{ x, y }));
		x+= 70.0f;
	}
	return buttons;
}

char M_button::get_label()
{
	return this->character;
}

char* M_button::get_char_for_GUI()
{
	return this->char_for_GUI;
}

Vector2 M_button::get_position()
{
    return this-> position;
}
