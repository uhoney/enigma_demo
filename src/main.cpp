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
	const int screenWidth = 1080;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Testauksia...");

	SetTargetFPS(30);

	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = { 10.0f, 20.0f };

	enigma::KeyBoard keyboard{};
	enigma::Lampboard lampboard{};


	//DEBUG: Testing rotor
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };

	// END INITIALIZATION -------------------------------------------------------------------

	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// UPDATE --------------------------------------------------------------------------
		Vector2 mouse_position = GetMousePosition();

		// CHECK IF KEY IS PRESSED => key pointer is set
		if (keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
		{
			//// DEBUG
			//lampboard.turn_on_lamp(keyboard.get_p_pressed_key()->get_label());
			TraceLog(LOG_INFO, "Pressed key: %c", keyboard.get_p_pressed_key()->get_label());
			rotor.turn_rotor();
			TraceLog(LOG_INFO, "Rotor position : %d", rotor.get_position_index());
			

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
		DrawRectangle(150, 25, 800, 650, BEIGE);
		DrawRectangle(175, 50, 750, 600, DARKGRAY);

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