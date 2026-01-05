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
	 * @class Lampboard
	 * Represents the lampboard of the Enigma machine.
	 */
	class Lampboard
	{
	private:
		std::vector<enigma::Lamp> lamps{};

	public:
		Lampboard();
		~Lampboard();

		std::vector<enigma::Lamp>& get_lamps();
		
		void turn_on_lamp(char);
		void reset_lamps();


	};
} // namespace enigma