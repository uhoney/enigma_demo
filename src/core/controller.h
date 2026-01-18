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
	 * Handles a key press event; runs the pressed key character through rotators 1-2-3, reflector, and back through rotors 3-2-1, turning rotors as needed.
	 * Unit tests are done separately for this function. Mouse simulation is painful and not worth the effort to change methods JUST for unit tests.
	 */
	void handle_key_press_event(Vector2&);

	/**
	 * DEBUG USE ONLY. This is basically a copy&paste version on handle_key_press_event but without mouse input handling and returns the output char.
	 */
	char debug_handle_key_press_event(char);

	/**
	 * Checks the rotor positions for turnovers and turs them rotors if needed.
	 * Also handles turning first rotor on every key press.
	 */
	void handle_rotor_turnovers();

	/**
	 * Load a few samples of sound effects for a key/button press in a vector.
	 */
	void load_sfx();

	/**
	 * Play a random sound effect for a key/button press from a vector.
	 */
	void play_random_key_sfx();

	/**
	* Handle rotor button press events to manually turn rotors.
	*/
	void handle_rotor_press_event(Vector2&, bool&, bool&);

	/**
	* Handle all mouse press events to check for key or rotor button presses.
	*/
	void handle_mouse_press_event();
};
