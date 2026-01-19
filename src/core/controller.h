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
 * Brief Handles the main Enigma machine logic.
 *
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
	* @brief Handles a keyboard key press event.
	*
	 * Handles a key press event; runs the pressed key character through rotators 1-2-3, reflector, and back through rotors 3-2-1, turning rotors as needed.
	 * Unit tests are done separately for this function. Mouse simulation is painful and not worth the effort to change methods JUST for unit tests.
	 */
	void handle_key_press_event(Vector2&);

	/**
	* @brief DEBUG USE ONLY.
	*
	 * DEBUG USE ONLY. This is basically a copy&paste version on handle_key_press_event but without mouse input handling and returns the output char.
	 */
	char debug_handle_key_press_event(char);

	/**
	* @brief Handles rotor turnovers.
	* 
	 * Checks the rotor positions for turnovers and turs them rotors if needed.
	 * Also handles turning first rotor on every key press.
	 */
	void handle_rotor_turnovers();

	/**
	* @brief Loads sound effects
	* 
	 * Loads a few .wav samples for a key/button press in a vector.
	 * Returns early if any sound effect fails to load and logs errors.
	 */
	void load_sfx();

	/**
	* @brief Plays a random sound effect
	* 
	 * Plays a random sound effect for a key/button press from a vector.
	 */
	void play_random_key_sfx();

	/**
	* @brief Handles rotor button press event.
	* 
	* Handles rotor button press events to manually turn rotors.
	* @param mouse_position Reference to the current mouse position.
	* @param mouse_pressed Reference to the mouse pressed state.
	* @param mouse_released Reference to the mouse released state.
	*/
	void handle_rotor_press_event(Vector2&, bool&, bool&);

	/**
	* @brief Handles mouse press events.
	* 
	* Handles all mouse press events to check if a keyboard key or rotor button has been pressed.
	*/
	void handle_mouse_press_event();
};
