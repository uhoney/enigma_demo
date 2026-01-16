#include "raylib.h"
#include <iostream>
#include "core/controller.h"
#include "ui/fonts.h"
#include "ui/layout.h"
#include "constants.h"
#include <memory>

// NOTE: Plan is to keep main "clean"

int main(void)
{
	// INITIALIZAZTION ----------------------------------------------------------------------
	InitWindow(ui::SCREEN_WIDTH, ui::SCREEN_HEIGHT, "Enigma demo");

	SetTargetFPS(30);
	SetTraceLogLevel(LOG_DEBUG);

	Font font{ ui::load_font() };
	Controller controller{};

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
	// Unload, delete, derefeence my own stuff
	UnloadFont(font);
	// NOTE: 'pressed_key' pointer in keyboard class is curlybrace init (on stack)
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}