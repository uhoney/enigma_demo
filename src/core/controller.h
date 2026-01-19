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
 * Controller manages the interaction between the keyboard, rotors, reflector, lampboard and sound.
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
	 * Handles a key press event:
	 * - Checks if rotors need to turn (and turns them)
	 * - Passes the pressed char through rotors 1-2-3
	 * - Passes char through reflector
	 * - Passes char through rotors 3-2-1 reversed
	 * - Turns on a corresponding lamp
	 * 
	 * Unit tests are done separately for this function. Mouse simulation is painful and not worth the effort to change methods JUST for unit tests.
	 */
	void handle_key_press_event(Vector2&);

	/**
	 * DEBUG USE ONLY. This is basically a copy&paste version on handle_key_press_event but without mouse input handling and returns the output char.
	 */
	char debug_handle_key_press_event(char);

	/**
	 * Checks the rotor positions for turnovers and turns ones that are allowed to turn. First rotor _always_ turns on key press.
	 */
	void handle_rotor_turnovers();

	/**
	 * Loads a few samples (.wav) for a key/button press and stores them in a vector. Returns early if any sound effect fails to load and only logs errors.
	 * Also closes audio device on failure to avoid memory leaks.
	 */
	void load_sfx();

	/**
	 * Plays a random sound effect for a key/button press from a vector. Does nothing if no sound effects are loaded.
	 */
	void play_random_key_sfx();

	/**
	* Handles rotor button press events to manually turn rotors.
	* @param mouse_position Reference to the current mouse position.
	* @param mouse_pressed Reference to the mouse pressed state.
	* @param mouse_released Reference to the mouse released state.
	*/
	void handle_rotor_press_event(Vector2&, bool&, bool&);

	/**
	* Handles all mouse press events to check if a keyboard key or rotor button has been pressed.
	*/
	void handle_mouse_press_event();
};
