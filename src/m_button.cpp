#include "m_button.h"

M_button::M_button(char & character)
{
	this->character = character;
	this->char_for_GUI = &character;
}

M_button::~M_button()
{
}

char M_button::get_label()
{
	return this->character;
}

char* M_button::get_char_for_GUI()
{
	return this->char_for_GUI;
}