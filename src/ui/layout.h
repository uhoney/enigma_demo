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
	/// @name Background case dimensions (x, y, width, height)
	/// @{
	inline constexpr Vector4 CASE_OUTLINE{ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	inline constexpr Vector4 CASE_INSIDE{ 25, 25, SCREEN_WIDTH - 50, SCREEN_HEIGHT - 50 };
	/// @}
	/**
	* Draws the background 'case'.
	*/
	void draw_background();

	/**
	* Handles drawing the entire @ref enigma::Keyboard by iterating through all @ref enigma::Key and calling draw_key() for each.
	*/
	void draw_keyboard(Font, enigma::Keyboard);

	/**
	* Draws a single @ref enigma::Key and its label at its position. Fetches size multiplier from the key to scale the key when pressed.
	*/
	void draw_key(Font, enigma::Key);

	/**
	* Handles drawing the entire @ref enigma::Lampboard by iterating through all @ref enigma::Lamp and calling draw_lamp() for each.
	*/
	void draw_lampboard(Font, enigma::Lampboard);

	/**
	* Draws a single @ref enigma::Lamp at its position. If the lamp is lit, draws it in yellow, otherwise in black.
	*/
	void draw_lamp(Font, enigma::Lamp);

	/**
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
	* Draws the @ref enigma::Rotor UI elements (increase/decrease buttons and triangles) for all rotors in the controller.
	*/
	void draw_rotor_buttons(Controller&);

	/**
	* Handles all @ref enigma::Rotor UI drawing by calling draw_rotor_index() and draw_rotor_buttons() for each rotor.
	*/
	void draw_rotor_ui(Font, Controller&);
}