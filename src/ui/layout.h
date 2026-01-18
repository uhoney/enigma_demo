#pragma once
#include "raylib.h"
#include "../constants.h"
#include "../core/keyboard.h"
#include "../core/lampboard.h"
#include "../core/rotor.h"
#include "../core/controller.h"

class Controller; // circular dependancy, forward declaration

namespace ui
{
	/**
	* @brief Defines the outline rectangle of the Enigma machine layout
	*/
	inline constexpr Vector4 CASE_OUTLINE{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	inline constexpr Vector4 CASE_INSIDE{ 25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50 };

	/**
	* @brief Draws the background (Enigma machine case)
	*/
	void draw_background();

	/**
	* @brief Draws the entire keyboard with given font and offset
	*/
	void draw_keyboard(Font, enigma::Keyboard);

	/**
	* @brief Draws a single key at its position with given font and offset
	*/
	void draw_key(Font, enigma::Key);

	/**
	* @brief Draws the entire lampboard with given font and offset
	*/
	void draw_lampboard(Font, enigma::Lampboard);

	/**
	* @brief Draws a single lamp at its position with given font and offset
	*/
	void draw_lamp(Font, enigma::Lamp);

	/**
	* @brief Draws the rotor index rectangle (display) and the rotor index number inside
	*/
	void draw_rotor_index(Font, Vector2, Vector2, enigma::Rotor);

	/**
	* @brief Draws the rotor UI buttons
	*/
	void draw_rotor_buttons(Controller&);

	/**
	* @brief Calls all rotor UI element draw functions (display, buttons)
	*/
	void draw_rotor_ui(Font, Controller&);
}