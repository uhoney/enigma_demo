#pragma once
#include "raylib.h"
#include "key.h"
#include <vector>
#include <string_view>
#include "constants.h"

namespace enigma
{
	class KeyBoard
	{
	private:
		/**
		* @brief Vector of all keys in the keyboard
		*/
		enigma::Key* p_key_pressed{ nullptr };						///< curlybrace initialization is on stack
		std::vector<enigma::Key> keys{};

	public:
		/**
		 * @brief Creates a fixed layout on screen
		 */
		KeyBoard();
		~KeyBoard();

		/**
		 * @brief Returns the vector of all keys
		 */
		std::vector<enigma::Key>& get_keys();

		/**
		* @brief Checks if a key is pressed and sets the pointer to the pressed key.
		* Boolean added for easier unit testing, mouse input can be simulated.
		*/
		bool isKeyPressed(Vector2&, bool);

		/**
		* @brief Checks if a key is released and resets the pointer to nullptr.
		* Boolean added for easier unit testing, mouse input can be simulated.
		*/
		bool isKeyReleased(bool);

		/**
		* @brief Returns pointer to the currently pressed key. nullptr if no key is pressed.
		*/
		enigma::Key* get_p_pressed_key();
	};
}
