#include <iostream>
#include "raylib.h"
#include "ui/fonts.h"
#include "ui/layout.h"
#include "constants.h"
#include "core/controller.h" 

int main(void)
{
	// INITIALIZAZTION ----------------------------------------------------------------------
	SetTraceLogLevel(LOG_NONE); // Disable raylib logging
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Enigma demo");
	InitAudioDevice();

	SetTargetFPS(30);
	
	enigma::Log::set_level(enigma::LogLevel::DEBUG);

	Font font{ ui::load_font() };
	Controller controller{};

	// END INITIALIZATION -------------------------------------------------------------------

	//	Main program loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{

		// UPDATE --------------------------------------------------------------------------

		controller.handle_mouse_press_event();

		// END UPDATE-----------------------------------------------------------------------

		// DRAW ----------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Draw my own stuff
		ui::draw_background();
		ui::draw_rotor_ui(font, controller);
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
	CloseAudioDevice();
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}