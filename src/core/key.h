#pragma once
#include "raylib.h"
#include "../constants.h"
#include <vector>
#include <string_view>

namespace enigma
{
	/// @name Key visual constants
	/// @{	
	inline constexpr float KEY_OUTER_RING{ 25.0f };			///< Outer ring radius
	inline constexpr float KEY_INNER_RING{ 23.0f };			///< Inner ring radius
	inline constexpr float KEY_PADDING{ 65.0f };			///< Distance between key centers
	inline constexpr float ROW_OFFSET_H{ 30.0f };          ///< Horizontal padding
	inline constexpr float ROW_OFFSET_V{ 65.0f };          ///< Vertical padding
	inline constexpr float KEY_FONT_SIZE{ 30.0f };               ///< Font size for key labels
	inline constexpr Vector2 KEY_FONT_OFFSET{ 7.0f, 15.0f };   ///< Font offset to center text in key
	/// @}

	/**
	* Represents a key in a keyboard in the Enigma machine
	*/
	class Key
	{
	private:
		/**
		 * Character label of the key.
		 */
		char character{};

		/**
		 * Position (x, y) of the key center
		 */
		Vector2 position{};

		/**
		 * Size multiplier for key scaling. Only used for UI draws.
		 */
		float size_multiplier{ 1.0f };

	public:
		/**
		 * @param character Character label of the key
		 * @param position Center position of the key
		 */
		Key(char, Vector2);
		~Key();

		char get_label() const;

		/**
		 * Returns the center position of a key
		 */
		Vector2 get_position() const;

		void set_size_multiplier(float);

		float get_size_multiplier() const;
	};
} // namespace enigma