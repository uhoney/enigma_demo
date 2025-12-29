#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "m_button.h"
#include <vector>

int main(void)
{

	// Create a list of all keys (buttons)
	std::vector<M_button> buttons{ M_button::create_all_buttons() };

	//for (auto& button : buttons)
	//{
	//	TraceLog(LOG_INFO, "Nappulan kirjain on: %c", button.get_label());
	//	// TraceLog(LOG_INFO, "Nappulan kirjain GUI:lle on: %c", *(button.get_char_for_GUI()));
	//}





	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Testauksia...");

	// Fonttihommat
	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);



	SetTargetFPS(30);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------


		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		

		//	BUTTONS
		for (auto& button : buttons)
		{
			button.set_size_multiplier(0.5f);
			DrawCircleV({ button.get_position() }, button.get_size_multiplier() * button.get_outer_ring_size(), LIGHTGRAY);	// Outer ring
			DrawCircleV({ button.get_position() }, button.get_size_multiplier() * button.get_inner_ring_size(), BLACK);		// Inner ring
			
			// TODO: Draw characters on top of buttons
			DrawTextEx(font, button.get_text(), { button.get_position().x-10, button.get_position().y-20 }, button.get_size_multiplier() * 40.0f, 0.0f, RAYWHITE);
			// NOTE: Letter offsets do not work when changing size_multiplier

		
		}

		//for (auto& button : buttons)
		//{
		//	button.set_size_multiplier(0.75f);
		//	button.set_new_position({ button.get_position().x, button.get_position().y + 100.0f });
		//}



		//for (auto& button : buttons)
		//{
		//	DrawCircleV({ button.get_position() }, button.get_size_multiplier() * button.get_outer_ring_size(), LIGHTGRAY);	// Outer ring
		//	DrawCircleV({ button.get_position() }, button.get_size_multiplier() * button.get_inner_ring_size(), BLACK);		// Inner ring

		//	// TODO: Draw characters on top of buttons
		//	// NOTE: Letter offsets
		//	DrawTextEx(font, button.get_text(), { button.get_position().x - 10, button.get_position().y - 20 }, button.get_size_multiplier()* 40.0f, 0.0f, RAYWHITE);
		//}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}