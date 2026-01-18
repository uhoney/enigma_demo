#pragma once
#include <vector>
#include "raylib.h"
#include "log.h"
#include "keyboard.h"
#include "key.h"
#include "rotor.h"
#include "reflector.h"
#include "lampboard.h"
#include "../ui/layout.h"

/**
 * @brief Controller manages the interaction between the keyboard, rotors, reflector, and lampboard.
 * @class Controller
 * Creates default keyboard, lampboard, 3 rotors, and reflector.
 */
class Controller
{
public:
	enigma::Keyboard keyboard{};
	enigma::Lampboard lampboard{};
	std::vector<enigma::Rotor> rotors{};
	enigma::Reflector reflector{};
	std::vector<Sound> sfx_key{};
	
	Controller();
	~Controller();

	/**
	 * @brief Handles a key press event; runs the pressed key character through rotators 1-2-3, reflector, and back through rotors 3-2-1, turning rotors as needed.
	 * Unit tests are done separately for this function. Mouse simulation is painful and not worth the effort to change methods JUST for unit tests.
	 * This method is just a copy of the debug version with mouse input handling and void type.
	 */
	void handle_key_press_event();

	/**
	 * @brief DEBUG USE ONLY. Handles a key press event; runs the pressed key character through rotators 1-2-3, reflector, and back through rotors 3-2-1, turning rotors as needed.
	 */
	char debug_handle_key_press_event(char);

	/**
	 * @brief Checks the rotor positions for turnovers and turs them rotors if needed.
	 * Also handles turning first rotor on every key press.
	 */
	void handle_rotor_turnovers();

	/**
	 * @brief Loads sound effects for key presses.
	 */
	void load_sfx();

	/**
	 * @brief Play a random sound effect for a key press.
	 */
	void play_random_key_sfx();

	/**
	* @brief Handles rotor button press events to manually turn rotors.
	*/
	void handle_rotor_press_event();
};
