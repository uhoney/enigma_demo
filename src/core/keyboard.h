#pragma once
#include "raylib.h"
#include "key.h"
#include <vector>
#include <string_view>
#include "../constants.h"

namespace enigma
{
	/**
	* @name Keyboard constants
	*@{
	*/
	inline constexpr float KEYBOARD_POSITION_X{ (SCREEN_WIDTH - (8 * KEY_PADDING)) / 2 };			///< Starting x position. 8 keys + keypadding = width.
	inline constexpr float KEYBOARD_POSITION_Y{ 600.0f };			///< Starting y position. Not yet decided
	/**@}*/

	/**
	* @brief Represents an on-screen keyboard with keys that can be pressed and released.
	* @class Keyboard
	* The Keyboard class manages a collection of Key objects, allowing for interaction through mouse input.
	*/
	class Keyboard
	{
	private:
		/**
		* @brief Vector of all keys in the keyboard
		*/
		std::vector<Key> keys{};

		/**
		* @brief Pointer to the currently pressed key. Should be nullptr if no key is beeing pressed.
		*/
		Key* p_key_pressed{ nullptr };

	public:
		/**
		 * @brief Creates a fixed layout on screen
		 */
		Keyboard();
		~Keyboard();

		/**
		 * @brief Returns the vector of all keys
		 */
		std::vector<Key>& get_keys();

		/**
		* @brief Checks if a key is pressed and sets the pointer to the pressed key.
		* Boolean added for easier unit testing (mouse input simulated)
		*/
		bool is_key_pressed(Vector2&, bool);

		/**
		* @brief Checks if a key is released and resets the pointer to nullptr.
		* Boolean added for easier unit testing, mouse input can be simulated.
		*/
		bool is_key_released(bool);

		/**
		* @brief Returns pointer to the currently pressed key. nullptr if no key is pressed.
		*/
		Key* get_pressed_key();
	};
}
