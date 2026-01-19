#pragma once
#include "raylib.h"
#include "lamp.h"
#include <vector>
#include "../constants.h"

namespace enigma
{
	/// @name Lampboard constants
	/// @{
	inline constexpr float LAMPBOARD_POSITION_X{ 100.0f };
	inline constexpr float LAMPBOARD_POSITION_Y{ 325.0f };
	/// @}

	/**
	* Represents the lampboard of the Enigma machine. Visual component. Contains multiple @ref enigma::Lamp objects arranged in a specific layout.
	*/
	class Lampboard
	{
	private:
		std::vector<Lamp> lamps{};

	public:
		Lampboard();
		~Lampboard();

		std::vector<Lamp>& get_lamps();

		void turn_on_lamp(char);
		
		void reset_lamps();


	};
}