#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "key.h"
#include "rotor.h"
#include "keyboard.h"
#include "constants.h"
#include "lampboard.h"
#include <vector>
#include <memory>

int main(void)
{
	// INITIALIZAZTION ----------------------------------------------------------------------
	const int screenWidth = enigma::SCREEN_WIDTH;
	const int screenHeight = enigma::SCREEN_HEIGHT;

	InitWindow(screenWidth, screenHeight, "Enigma demo");

	SetTargetFPS(30);
	
	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = { 10.0f, 20.0f };

	enigma::KeyBoard keyboard{};
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };
	enigma::Rotor rotor_2{ enigma::ROTOR_II_WIRING , enigma::ROTOR_II_TURNOVER };
	
	enigma::Reflector reflector{};
	enigma::Lampboard lampboard{};
	
	

	// END INITIALIZATION -------------------------------------------------------------------

	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// UPDATE --------------------------------------------------------------------------
		Vector2 mouse_position = GetMousePosition();

		// CHECK IF KEY IS PRESSED => key pointer is set
		if (keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
		{

			char unnamed_char = keyboard.get_p_pressed_key()->get_label();
			TraceLog(LOG_INFO, "Pressed key: %c", unnamed_char);
			rotor.turn_rotor();
			unnamed_char = rotor.pass_through(unnamed_char);
			TraceLog(LOG_INFO, "Rotor output: %c", unnamed_char);
			unnamed_char = reflector.swap_character(unnamed_char);
			TraceLog(LOG_INFO, "Reflector output: %c", unnamed_char);
			unnamed_char = rotor.reverse_pass_through(unnamed_char);
			TraceLog(LOG_INFO, "Rotor reverse output: %c", unnamed_char);
			lampboard.turn_on_lamp(unnamed_char);

		}

		// FINALLY CHECK IF KEY IS RELEASED => key is nullptr again
		if (keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
		{
			lampboard.reset_lamps();
		}
		// END UPDATE-----------------------------------------------------------------------


		// DRAW ----------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// BACKGROUND
		// TODO: Abstract case drawing to helpers
		

		// LAMPBOARD
		for (auto& lamp : lampboard.get_lamps())
		{
			lamp.draw_lamp(font, font_offset);
		}

		//	DRAW KEYBOARD
		for (auto& key : keyboard.get_keys())
		{
			key.draw_key(font, font_offset);
		}
		EndDrawing();
		// END DRAW ------------------------------------------------------------------------
	}
	//	De-Initialization
	//--------------------------------------------------------------------------------------
	// Unload, delete, derefeence my own stuff
	UnloadFont(font);
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}