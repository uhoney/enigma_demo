#pragma once
#include "raylib.h"
#include <list>

class M_button
{
private:
	char character{};
	char* char_for_GUI{};

public:
	M_button(char &);
	~M_button();

	static std::list<M_button> button_list{};

	char get_label();
	char* get_char_for_GUI();

	void draw_button()
};