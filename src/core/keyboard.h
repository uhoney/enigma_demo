#pragma once
#include "raylib.h"
#include "key.h"
#include <vector>
#include <string_view>
#include "../constants.h"

namespace enigma
{
	/// @name Keyboard positioning constants
	/// @{
	inline constexpr float KEYBOARD_POSITION_X{ (SCREEN_WIDTH - (8 * KEY_PADDING)) / 2 };	///< Starting x position. 8 keys + keypadding = width.
	inline constexpr float KEYBOARD_POSITION_Y{ 575.0f };									///< Starting y position. Not yet decided
	/// @}

	/**
	* Represents a keyboard with keys that can be pressed and released. The keyboard class manages a collection of @ref enigma::Key objects, allowing for interaction through mouse input.
	*/
	class Keyboard
	{
	private:
		/**
		* Vector of all keys in the keyboard
		*/
		std::vector<Key> keys{};

		/**
		* Pointer to the currently pressed key. Should be nullptr if no key is being pressed.
		*/
		Key* p_key_pressed{ nullptr };

	public:
		Keyboard();
		~Keyboard();

		/**
		 * Returns a vector of all keys in keyboard.
		 */
		std::vector<Key>& get_keys();

		/**
		* Checks if a key is pressed and sets the pointer p_key_pressed to the pressed key. Boolean added for easier unit testing, mouse input can be simulated
		*/
		bool is_key_pressed(const Vector2&, bool);

		/**
		* Checks if a key is released and sets p_pressed_key to nullptr. Boolean added for easier unit testing, mouse input can be simulated.
		*/
		bool is_key_released(bool);

		/**
		* Returns a pointer to the currently pressed key. nullptr if no key is pressed.
		*/
		Key* get_pressed_key();
	};
}
