#pragma once

#include "../constants.h"
#include <vector>
#include "raylib.h"

namespace enigma
{
	/**
	 * @name Lamp constants
	 *@{
	 */
	inline constexpr float LAMP_RADIUS{ 30.0f };          ///< Lamp radius
	inline constexpr float LAMP_PADDING{ 75.0f };         ///< Distance between lamp centers
	/**@}*/

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
        /**
		* @brief Draw the lamp at its position using the provided font.
        */
		void draw_lamp(Font, Vector2);

		bool get_is_lit() const;
        void toggle_lamp();

    };
}