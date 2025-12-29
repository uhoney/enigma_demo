#pragma once
#include "raylib.h"
#include <vector>

class M_button
{
private:
	char character{};
	char* char_for_GUI{};
	Vector2 position{};

public:
	M_button(char &, Vector2 pos);
	~M_button();

	static std::vector<M_button>create_all_buttons();

	char get_label();
	char* get_char_for_GUI();

	Vector2 get_position();

};