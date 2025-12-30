#pragma once
#include "raylib.h"
#include <vector>
#include <string>

static constexpr float BUTTON_PADDING{ 75.0f };
static constexpr float BUTTON_OUTER_RING{ 30.0f };
static constexpr float BUTTON_INNER_RING{ 25.0f };

class M_button
{
private:
	char character[2]{};	// includes null terminate '\0'
	Vector2 position{};
	float size_multiplier{ 1.0f };
	float outer_ring{ BUTTON_OUTER_RING };
	float inner_ring{ BUTTON_INNER_RING };
	// TODO: Button states (pressed / not pressed)

public:
	M_button(char, Vector2 pos);
	~M_button();

	char get_label() const;
	const char* get_text();
	Vector2 get_position() const;
	float get_button_size() const;
	void set_size_multiplier(float);
	void draw_button(Font, Vector2);

	// STATIC METHODS
	static std::vector<M_button>create_all_buttons(float, float, std::string);
};