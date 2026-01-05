//#include "raylib.h"
//#include <iostream>
//#include "core/reflector.h"
//#include "core/key.h"
//#include "core/keyboard.h"
//#include "core/rotor.h"
//#include "core/lampboard.h"
//#include "core/controller.h"
//#include "ui/fonts.h"
//#include "ui/layout.h"
//#include "constants.h"
//#include <vector>
//#include <memory>
//
//int main(void)
//{
//	// INITIALIZAZTION ----------------------------------------------------------------------
//	InitWindow(ui::SCREEN_WIDTH, ui::SCREEN_HEIGHT, "Enigma demo");
//
//	SetTargetFPS(30);
//	SetTraceLogLevel(0);
//
//	Font font{ ui::load_font() };
//
//	enigma::KeyBoard keyboard{};
//	enigma::Lampboard lampboard{};
//	enigma::Reflector reflector{};
//	
//
//	// END INITIALIZATION -------------------------------------------------------------------
//
//	//	Main program loop
//	while (!WindowShouldClose()) // Detect window close button or ESC key
//	{
//		// UPDATE --------------------------------------------------------------------------
//		Vector2 mouse_position = GetMousePosition();
//
//		// CHECK IF KEY IS PRESSED => key pointer is set
//		if (keyboard.isKeyPressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
//		{
//			//enigma::process_key_press(keyboard.get_p_pressed_key()->get_label());
//		}
//
//
//		// FINALLY CHECK IF KEY IS RELEASED => key is nullptr again
//		if (keyboard.isKeyReleased(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
//		{
//			lampboard.reset_lamps();
//		}
//		// END UPDATE-----------------------------------------------------------------------
//
//
//		// DRAW ----------------------------------------------------------------------------
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//
//		// Draw my own stuff
//		ui::draw_background();
//		ui::draw_keyboard(font, ui::FONT_OFFSET, keyboard);
//		ui::draw_lampboard(font, ui::FONT_OFFSET, lampboard);
//
//		EndDrawing();
//		// END DRAW ------------------------------------------------------------------------
//	}
//	//	De-Initialization
//	//--------------------------------------------------------------------------------------
//	// Unload, delete, derefeence my own stuff
//	UnloadFont(font);
//	// NOTE: 'pressed_key' pointer in keyboard class is curlybrace init (on stack)
//	CloseWindow(); // Close window and OpenGL context
//	//--------------------------------------------------------------------------------------
//
//	return 0;
//}