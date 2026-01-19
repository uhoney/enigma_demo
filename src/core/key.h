#pragma once
#include "raylib.h"
#include "../constants.h"
#include <vector>
#include <string_view>

namespace enigma
{
	inline constexpr float KEY_OUTER_RING{ 25.0f };			///< Outer ring radius
	inline constexpr float KEY_INNER_RING{ 23.0f };			///< Inner ring radius
	inline constexpr float KEY_PADDING{ 65.0f };			///< Distance between key centers
	inline constexpr float ROW_OFFSET_H{ 30.0f };          ///< Horizontal padding
	inline constexpr float ROW_OFFSET_V{ 65.0f };          ///< Vertical padding
	inline constexpr float KEY_FONT_SIZE{ 30.0f };               ///< Font size for key labels
	inline constexpr Vector2 KEY_FONT_OFFSET{ 7.0f, 15.0f };   ///< Font offset to center text in key

	/**
	* Represents a key in the Enigma machine.
	*/
	class Key
	{
	private:
		/**
		 * @brief Character label of the key. Includes null terminate '\0'
		 */
		char character{};

		/**
		 * @brief Position (x, y) of the key center
		 */
		Vector2 position{};

		/**
		 * @brief Size multiplier for key scaling (e.g. when pressed)
		 */
		float size_multiplier{ 1.0f };

	public:
		/**
		* @brief Default constructor
		 * @param character Character label of the key
		 * @param position Position of the key center
		 *
		 * Constructor uses curlybrace initialization.
		 */
		Key(char, Vector2);
		~Key();

		/**
		 * @brief Return the character label of the key (without null terminate)
		 */
		char get_label() const;

		/**
		 * @brief Return Vector2 position of the key center
		 */
		Vector2 get_position() const;

		/**
		 * @brief Set size multiplier for the key
		 */
		void set_size_multiplier(float);

		/**
		* @brief Return the size multiplier
		*/
		float get_size_multiplier() const;
	};
} // namespace enigma