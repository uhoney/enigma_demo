#pragma once

#include "constants.h"
#include <vector>
#include "raylib.h"

namespace enigma
{
    class Lamp
    {
    private:
		char character[2]{};
        bool is_lit{ false };
        Vector2 position{};

    public:
        Lamp(char, const Vector2);
		~Lamp();

        
        char get_label() const;
		const char* get_text();     // for raylib DrawTextEx()
		void draw_lamp(Font, Vector2);

		bool get_is_lit() const;
        void toggle_lamp();

    };
}