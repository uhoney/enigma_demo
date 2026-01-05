#include "raylib.h"
#include <iostream>
#include "core/reflector.h"
#include "core/key.h"
#include "core/rotor.h"
#include "core/keyboard.h"
#include "constants.h"
#include "core/lampboard.h"
#include "ui/fonts.h"
#include "ui/layout.h"
#include <vector>
#include <memory>

int main(void)
{
	// INITIALIZAZTION ----------------------------------------------------------------------
	InitWindow(ui::SCREEN_WIDTH, ui::SCREEN_HEIGHT, "Enigma demo");

	SetTargetFPS(30);

	Font font{ ui::load_font() };

	enigma::KeyBoard keyboard{};
	enigma::Lampboard lampboard{};
	enigma::Reflector reflector{};
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING , enigma::ROTOR_I_TURNOVER };
	enigma::Rotor rotor_2{ enigma::ROTOR_II_WIRING , enigma::ROTOR_II_TURNOVER };
	enigma::Rotor rotor_3{ enigma::ROTOR_III_WIRING , enigma::ROTOR_III_TURNOVER };
		
	// END INITIALIZATION -------------------------------------------------------------------

	//	Main program loop
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

		// Draw my own stuff
		ui::draw_background();
		ui::draw_keyboard(font, ui::FONT_OFFSET, keyboard);
		ui::draw_lampboard(font, ui::FONT_OFFSET, lampboard);

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