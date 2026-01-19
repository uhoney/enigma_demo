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
	inline constexpr float LAMP_FONT_SIZE{ 40.0f };               ///< Font size for lamp labels
	inline constexpr Vector2 LAMP_FONT_OFFSET{ 10.0f, 20.0f };   ///< Font offset to center text in lamp
	/**@}*/

	/**
	* @brief A lamp that lights up to indicate a cipher/decipher character.
	* @class Lamp
	* Each lamp corresponds to a character in the alphabet and lights up when that character is the output of the Enigma machine.
	*/
	class Lamp
	{
	private:
		char character{};
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