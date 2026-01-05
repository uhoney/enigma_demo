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

		/**
		* @brief Get the label character of the lamp.
		*/
		char get_label() const;
		
		/**
		* @brief Get the text representation of the lamp's character.
		*/
		const char* get_text();     // for raylib DrawTextEx()

		/**
		* @brief Check if the lamp is currently lit.
		*/
		bool get_is_lit() const;
		
		/**
		* @brief Get the position of the lamp.
		*/
		Vector2 get_position() const;

		/**
		* @brief Toggle the lamp's lit state.
		*/
		void toggle_lamp();

    };
}