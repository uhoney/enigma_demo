#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "key.h"
#include <vector>
#include <memory>

int main(void)
{

	//	Create a vector of all keys -- Keyboard has fixed layout
	std::vector<Key> keyboard{Key::create_all_keys(250.0f, 400.0f, "QWERTZUIOASDFGHJKPYXCVBNML")};

	//--------------------------------------------------------------------------------------
	//	Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Testauksia...");

	SetTargetFPS(30);

	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = {10.0f, 20.0f};

	// Testing pointer to pressed key
	Key *p_key_pressed {nullptr};



	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		//	Update
		//----------------------------------------------------------------------------------

		Vector2 mouse_position = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && p_key_pressed == nullptr)
		{
			for (auto &key : keyboard)
			{
				if (CheckCollisionPointCircle(mouse_position, key.get_position(), key.get_key_size()))
				{
					TraceLog(LOG_INFO, "Key %c pressed!", key.get_label());
					p_key_pressed = &key;
					p_key_pressed->set_size_multiplier(0.8f);
					break;
				}
			}
		}

		else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && p_key_pressed != nullptr)
		{
			p_key_pressed->set_size_multiplier(1.0f);
			p_key_pressed = nullptr;
		}
		//----------------------------------------------------------------------------------

		//	Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//	DRAW KEYBOARD
		for (auto &key : keyboard)
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
	p_key_pressed = nullptr;
	delete p_key_pressed;
	//
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}