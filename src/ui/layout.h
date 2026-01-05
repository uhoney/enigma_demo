#pragma once
#include "raylib.h"
#include "../core/keyboard.h"
#include "../core/lampboard.h"

namespace ui
{
	inline constexpr int SCREEN_WIDTH = 1080;
	inline constexpr int SCREEN_HEIGHT = 800;

	/**
	* @brief Defines the outline rectangle of the Enigma machine layout
	*/
	inline constexpr Vector4 CASE_OUTLINE{ 150, 25, 800, 650 };
	inline constexpr Vector4 CASE_INSIDE{ 175, 50, 750, 600 };

	/**
	* @brief Draws the background (Enigma machine case)
	*/
	void draw_background();

	/**
	* @brief Draws the entire keyboard with given font and offset
	*/
	void draw_keyboard(Font, Vector2, enigma::KeyBoard);

	/**
	* @brief Draws a single key at its position with given font and offset
	*/
	void draw_key(Font, Vector2, enigma::Key);

	/**
	* @brief Draws the entire lampboard with given font and offset
	*/
	void draw_lampboard(Font, Vector2, enigma::Lampboard);

	/**
	* @brief Draws a single lamp at its position with given font and offset
	*/
	void draw_lamp(Font, Vector2, enigma::Lamp);
}