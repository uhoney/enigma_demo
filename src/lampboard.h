#include "raylib.h"
#include "lamp.h"
#include <vector>
#include "constants.h"

namespace enigma
{
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