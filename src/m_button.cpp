#include "m_button.h"
#include "m_button.h"
#include "m_button.h"
#include "m_button.h"

M_button::M_button(char character, Vector2 position) :
	character{ character, '\0' },
	position{ position }
{
}

M_button::~M_button()
{
}

std::vector<M_button> M_button::create_all_buttons()
{
	std::vector<M_button> buttons;
	float x = 200.0f;
	float y = 400.0f;

	// create buttons
	std::string button_row_1{ "QWERTZUIO" };	// 9 nappia

	for (char character : button_row_1)
	{
		buttons.emplace_back(character, Vector2{ x,y });
		x += BUTTON_PADDING;
	}
	//std::string buttons_row_2 {"ASDFGHJK"};	// 8 nappia
	//std::string buttons_row_3 {"PYXCVBNML"};	// 9 nappia


	return buttons;
}

char M_button::get_label()
{
	return this->character[0];		// null terminate merkki mukana!
}

Vector2 M_button::get_position()
{
	return this->position;
}

float M_button::get_size_multiplier()
{
	return this->size_multiplier;
}

float M_button::get_outer_ring_size()
{
	return this->outer_ring;
}

float M_button::get_inner_ring_size()
{
	return this->inner_ring;
}

const char* M_button::get_text()
{
	return this->character;
}

void M_button::set_size_multiplier(float new_size_multiplier)
{
	this->size_multiplier = new_size_multiplier;
}

void M_button::set_new_position(Vector2 position)
{
	this->position = position;
}

