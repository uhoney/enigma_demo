#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "m_button.h"
#include <vector>

int main(void)
{

	//	Create a list of all keys (buttons)
	std::vector<M_button> buttons{ M_button::create_all_buttons(250.0f, 400.0f, "QWERTZUIOASDFGHJKPYXCVBNML") };

	// for (auto& button : buttons)
	//{
	//	TraceLog(LOG_INFO, "Nappulan kirjain on: %c", button.get_label());
	//}

	//--------------------------------------------------------------------------------------
	//	Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Testauksia...");

	SetTargetFPS(30);

	//	TODO: Testing fonts and character offsets, USE A MONOSPACED FONT !!!
	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = { 10.0f, 20.0f };
	
	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		//----------------------------------------------------------------------------------
		//	Update
		//----------------------------------------------------------------------------------

		//	TODO: mouse press detection for buttons

		//----------------------------------------------------------------------------------
		//	Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//	DRAW BUTTONS
		//	NOTE: Simple drawing moved inside the button class, no fancy stuff. Main is cleaner now.
		for (auto& button : buttons)
		{
			// FIXME: Maybe a state for button pressed / not pressed
			button.draw_button(font, font_offset);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	//	De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();	// Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}