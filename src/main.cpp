#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "key.h"
#include "keyboard.h"
#include <vector>
#include <memory>

int main(void)
{
	//--------------------------------------------------------------------------------------
	//	Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 800;
	
	InitWindow(screenWidth, screenHeight, "Testauksia...");
	
	SetTargetFPS(30);
	
	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = {10.0f, 20.0f};
	
	enigma::KeyBoard keyboard {};

	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		//	Update
		//----------------------------------------------------------------------------------

		Vector2 mouse_position = GetMousePosition();

		keyboard.isKeyPressed(mouse_position);

		//	Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//	DRAW KEYBOARD
		for (auto &key : keyboard.get_keys())
		{
			key.draw_key(font, font_offset);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	//	De-Initialization
	//--------------------------------------------------------------------------------------
	// Unload, delete, derefeence my own stuff
	UnloadFont(font);
	//p_key_pressed = nullptr;
	//delete p_key_pressed;
	//
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}