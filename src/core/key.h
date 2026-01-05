#pragma once
#include "raylib.h"
#include "../constants.h"
#include <vector>
#include <string_view>

namespace enigma
{
	/**
	 * @name Key constants
	 *@{
	 */
	inline constexpr float KEY_OUTER_RING{ 30.0f };       ///< Outer ring radius
	inline constexpr float KEY_INNER_RING{ 25.0f };       ///< Inner ring radius
	inline constexpr float KEY_PADDING{ 75.0f };          ///< Distance between button centers
	/**@}*/

	/**
	 * @class Key
	 * Represents a key in the Enigma machine.
	 */
	class Key
	{
	private:
		/**
		 * @brief Character label of the v. Includes null terminate '\0'
		 */
		char character[2]{};
		/**
		 * @brief Position of the key center
		 */
		Vector2 position{};
		/**
		 * @brief Size multiplier for key scaling (e.g. when pressed)
		 */
		float size_multiplier{ 1.0f };

	public:
		/**
		 * @brief Constructor uses curlybrace initialization
		 * @param char Character label of the key
		 * @param pos Position of the key center
		 */
		Key(char, Vector2 pos);
		~Key();

		/**
		 * @brief Returns the character label of the key
		 */
		char get_label() const;

		/**
		 * @brief Returns the character label
		 */
		const char* get_text();

		/**
		 * @brief Returns the character label as a C-string (for raylib DrawTextEx())
		 */
		Vector2 get_position() const;

		/**
		 * @brief Returns the inner key size (inner ring radius)
		 */
		
		void set_size_multiplier(float);
	};
} // namespace enigma