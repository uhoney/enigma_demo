#include "raylib.h"
#include "ui/fonts.h"
#include "ui/layout.h"
#include "constants.h"
#include <iostream>
#include "core/controller.h"

int main(void)
{
	// INITIALIZAZTION ----------------------------------------------------------------------
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Enigma demo");

	SetTargetFPS(30);
	SetTraceLogLevel(LOG_ERROR);

	Font font{ ui::load_font() };
	Controller controller{};

	// TODO: not here, move to controller
	//// TESTING SFX --------------------------------------------------------------------------
	//Sound sfx_key_press_1{ LoadSound("assets/sfx/typewriter_1.wav") };
	//Sound sfx_key_press_2{ LoadSound("assets/sfx/typewriter_2.wav") };
	//Sound sfx_key_press_3{ LoadSound("assets/sfx/typewriter_3.wav") };
	//Sound sfx_key_press_4{ LoadSound("assets/sfx/typewriter_4.wav") };

	//if (sfx_key_press_1.frameCount == 0 || sfx_key_press_2.frameCount == 0 ||
	//	sfx_key_press_3.frameCount == 0 || sfx_key_press_4.frameCount == 0)
	//{
	//	std::cerr << "Error loading sound effects!" << std::endl;
	//	CloseAudioDevice();
	//	CloseWindow();
	//	return -1;
	//}
	//// END TESTING SFX----------------------------------------------------------------------


	// END INITIALIZATION -------------------------------------------------------------------

	//	Main program loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// UPDATE --------------------------------------------------------------------------

		// Check if key is pressed/released and handle accordingly
		controller.handle_key_press_event();
		// END UPDATE-----------------------------------------------------------------------

		// DRAW ----------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw my own stuff
		ui::draw_background();
		ui::draw_keyboard(font, controller.keyboard);
		ui::draw_lampboard(font, controller.lampboard);

		// Draw mouse coordinates (for debugging)
		Vector2 mouse_pos{ GetMouseX(), GetMouseY() };
		DrawTextEx(font, TextFormat("Mouse: [%.0f, %.0f]", mouse_pos.x, mouse_pos.y), { 10.0f, 10.0f }, static_cast<float>(font.baseSize), 1.0f, RAYWHITE);

		EndDrawing();
		// END DRAW ------------------------------------------------------------------------
	}
	//	De-Initialization
	//--------------------------------------------------------------------------------------
	// Unload, delete, dereference my own stuff
	UnloadFont(font);
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}