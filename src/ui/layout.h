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
	/// @defgroup Machine 'case' dimensions
	/// @{
	inline constexpr Vector4 CASE_OUTLINE{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; ///< Outer dimensions of the machine 'case' outline
	inline constexpr Vector4 CASE_INSIDE{ 25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50 }; ///< Inner dimensions of the machine 'case' inside area
	/// @}

	/**
	* @brief Draws the background
	*
	* Draws the machine 'case' outline and inside area.
	*/
	void draw_background();

	/**
	* @brief Handles drawing the entire keyboard
	*
	* Handles drawing the entire keyboard by iterating through all keys and calling draw_key() for each.
	*/
	void draw_keyboard(Font, enigma::Keyboard);

	/**
	* @brief Draws a single key
	*
	* Draws a single key and its label at its position. Fetches size multiplier from the key to scale the key when pressed.
	*/
	void draw_key(Font, enigma::Key);

	/**
	* @brief Handles drawing the entire lampboard
	*
	* Handles drawing the entire lampboard by iterating through all lamps and calling draw_lamp() for each.
	*/
	void draw_lampboard(Font, enigma::Lampboard);

	/**
	* @brief Draws a single lamp
	*
	* Draws a single lamp at its position. If the lamp is lit, draws it in yellow, otherwise in black.
	*/
	void draw_lamp(Font, enigma::Lamp);

	/**
	* @brief Draws the rotor index display
	*
	* Draws the rotor index display at the given position, showing the rotor's current index.
	* Draws a rectangle with an outline effect and the rotor index text inside.
	*
	* @param font Font to use for drawing text
	* @param rect_position Top-left position of the rectangle to draw
	* @param rect_size Size of the rectangle to draw
	* @param rotor The rotor to be displayed
	*/
	void draw_rotor_index(Font, Vector2, Vector2, enigma::Rotor);

	/**
	* @brief Draws the rotor UI buttons
	*
	* Draws the rotor UI elements (increase/decrease buttons and triangles) for all rotors in the controller.
	*/
	void draw_rotor_buttons(Controller&);

	/**
	* @brief Handles all rotor UI drawing
	*
	* Handles all rotor UI drawing by calling draw_rotor_index() and draw_rotor_buttons() for each rotor.
	*/
	void draw_rotor_ui(Font, Controller&);
}