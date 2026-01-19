#include <iostream>
#include "raylib.h"
#include "ui/fonts.h"
#include "ui/layout.h"
#include "constants.h"
#include "core/controller.h" 

int main(void)
{
	SetTraceLogLevel(LOG_NONE);		// Disable raylib logging
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Enigma demo");
	InitAudioDevice();				// Initialize audio context
	SetTargetFPS(30);

	enigma::Log::set_level(enigma::LogLevel::DEBUG);
	bool draw_coordinates{ true };	// Draw mouse coordinates for debugging
	Font font{ ui::load_font() };
	Controller controller{};

	while (!WindowShouldClose())
	{
		// UPDATE --------------------------------------------------------------------------
		controller.handle_mouse_press_event();

		// DRAW ----------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		ui::draw_background();
		ui::draw_rotor_ui(font, controller);
		ui::draw_keyboard(font, controller.keyboard);
		ui::draw_lampboard(font, controller.lampboard);

		if (draw_coordinates)
		{
			Vector2 mouse_pos{ GetMouseX(), GetMouseY() };
			DrawTextEx(font, TextFormat("Mouse: [%.0f, %.0f]", mouse_pos.x, mouse_pos.y), { 10.0f, 10.0f }, static_cast<float>(font.baseSize), 1.0f, GRAY);
		}
		
		EndDrawing();
	}
	
	UnloadFont(font); // Unload font from VRAM
	CloseAudioDevice(); // Close audio context
	CloseWindow(); // Close window and OpenGL context

	return 0;
}