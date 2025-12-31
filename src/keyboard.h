#pragma once
#include "raylib.h"
#include "key.h"
#include <vector>
#include <string_view>

namespace enigma
{
	class KeyBoard

	{
	private:
		/**
		* @name Keyboard constants
		* Keyboard drawing and character constants
		*/
		//@{
		static constexpr float KEY_PADDING{ 75.0f };				///< Distance between button centers
		static constexpr std::string_view ENIGMA_KEYBOARD_CHARACTERS{ "QWERTZUIOASDFGHJKPYXCVBNML" };		///< Default keyboard characters
		static constexpr float KEYBOARD_POSITION_X{ 250.0f };		///< Starting x position
		static constexpr float KEYBOARD_POSITION_Y{ 400.0f };		///< Starting y position
		//@}
		/**
		* @brief Vector of all keys in the keyboard
		*/
		enigma::Key* p_key_pressed{ nullptr };
		std::vector<enigma::Key> keys{};

	public:
		/**
		 * @brief Creates a fixed layout to given position on screen
		 * @param x Starting x position
		 * @param y Starting y position
		 */
		KeyBoard();
		~KeyBoard();

		/**
		 * @brief Returns the vector of all keys
		 */
		std::vector<enigma::Key>& get_keys();

		void isKeyPressed(Vector2&);

	};
}
