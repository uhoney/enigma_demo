#pragma once
#include "raylib.h"
#include <vector>
#include <string>


class M_button
{
private:
	static constexpr float BUTTON_PADDING{ 75.0f };
	char character[2]{};	// includes null terminate '\0'
	Vector2 position{};
	float size_multiplier{ 1.0f };
	float outer_ring{ 30.0f };
	float inner_ring{ 25.0f };

public:
	M_button(char, Vector2 pos);
	~M_button();

	static std::vector<M_button>create_all_buttons();

	char get_label();

	Vector2 get_position();
	float get_size_multiplier();
	float get_outer_ring_size();
	float get_inner_ring_size();
	const char* get_text();
	void set_size_multiplier(float);
	void set_new_position(Vector2);
};