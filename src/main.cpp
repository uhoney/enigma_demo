#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "key.h"
#include "rotor.h"
#include "keyboard.h"
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
	// END INITIALIZATION -------------------------------------------------------------------

	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// UPDATE --------------------------------------------------------------------------
		Vector2 mouse_position = GetMousePosition();

		// CHECK IF KEY IS PRESSED => key pointer is set
		keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
		// NOTE: Everything goes between isKeyPressed() and isKeyReleased()!!



		// FINALLY CHECK IF KEY IS RELEASED => key is nullptr again
		keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON));
		// END UPDATE-----------------------------------------------------------------------


		// DRAW ----------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

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