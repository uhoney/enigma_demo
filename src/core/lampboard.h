#pragma once
#include "raylib.h"
#include "lamp.h"
#include <vector>
#include "../constants.h"

namespace enigma
{
	/**
	 * @name Lampboard position constants
	 *@{
	 */
	inline constexpr float LAMPBOARD_POSITION_X{ 250.0f }; ///< Starting x position
	inline constexpr float LAMPBOARD_POSITION_Y{ 100.0f }; ///< Starting y position
	/**@}*/

	/**
	* @brief Represents the lampboard of the Enigma machine.
	* @class Lampboard
	* Visual component. Contains multiple Lamp objects arranged in a specific layout.
	*/
	class Lampboard
	{
	private:
		std::vector<Lamp> lamps{};

	public:
		Lampboard();
		~Lampboard();

		/**
		* @brief Get the vector of lamps on the lampboard.
		*/
		std::vector<Lamp>& get_lamps();

		/**
		* @brief Turn on the lamp corresponding to the given character.
		*/
		void turn_on_lamp(char);
		
		/**
		* @brief Reset all lamps to the unlit state.
		*/
		void reset_lamps();


	};
} // namespace enigma