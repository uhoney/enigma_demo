#pragma once
#include <string_view>

namespace enigma
{
	static constexpr std::string_view ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	static constexpr std::string_view ENIGMA_KEYBOARD_CHARACTERS{ "QWERTZUIOASDFGHJKPYXCVBNML" };

	/**
	 * @name Reflector wiring configurations
	 * @{
	 */
	static constexpr std::string_view UKW_A_WIRING = "EJMZALYXVBWFCRQUONTSPIKHGD";
	static constexpr std::string_view UKW_B_WIRING = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	static constexpr std::string_view UKW_C_WIRING = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
	/** @} */
	/**
	 * @name Rotor wiring configurations and corresponding turnover notches
	 * @{
	 */
	static constexpr std::string_view ROTOR_I_WIRING = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	static constexpr char ROTOR_I_TURNOVER = 'Q';
	static constexpr std::string_view ROTOR_II_WIRING = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	static constexpr char ROTOR_II_TURNOVER = 'E';
	static constexpr std::string_view ROTOR_III_WIRING = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	static constexpr char ROTOR_III_TURNOVER = 'V';
	/** @} */

	/**
	 * @name Button and lamp constants
	 *@{
	 */
	static constexpr float KEY_OUTER_RING{ 30.0f };       ///< Outer ring radius
	static constexpr float KEY_INNER_RING{ 25.0f };       ///< Inner ring radius
	static constexpr float KEY_PADDING{ 75.0f };          ///< Distance between button centers
	static constexpr float LAMP_RADIUS{ 30.0f };          ///< Lamp radius
	static constexpr float LAMP_PADDING{ 75.0f };         ///< Distance between lamp centers
	static constexpr float LAMPBOARD_POSITION_X{ 250.0f }; ///< Starting x position
	static constexpr float LAMPBOARD_POSITION_Y{ 100.0f }; ///< Starting y position
	static constexpr float KEYBOARD_POSITION_X{ 250.0f }; ///< Starting x position
	static constexpr float KEYBOARD_POSITION_Y{ 400.0f }; ///< Starting y position
	/**@}*/
}