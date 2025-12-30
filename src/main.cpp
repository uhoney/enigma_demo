#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "m_button.h"
#include <vector>
#include <memory>

int main(void)
{

	//	Create a list of all keys (buttons)
	std::vector<M_button> buttons{M_button::create_all_buttons(250.0f, 400.0f, "QWERTZUIOASDFGHJKPYXCVBNML")};

	//--------------------------------------------------------------------------------------
	//	Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 1080;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Testauksia...");

	SetTargetFPS(30);

	Font font = LoadFontEx("assets/fonts/UbuntuMono-R.ttf", 80, NULL, 0);
	Vector2 font_offset = {10.0f, 20.0f};

	// Testing pointer to pressed button
	M_button *p_pressed_button {nullptr};

	//	Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		//	Update
		//----------------------------------------------------------------------------------

		Vector2 mouse_position = GetMousePosition();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && p_pressed_button == nullptr)
		{
			for (auto &button : buttons)
			{
				if (CheckCollisionPointCircle(mouse_position, button.get_position(), button.get_button_size()))
				{
					TraceLog(LOG_INFO, "Nappulaa %c painettu!", button.get_label());
					p_pressed_button = &button;
					p_pressed_button->set_size_multiplier(0.8f);
					break;
				}
			}
		}

		else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && p_pressed_button != nullptr)
		{
			p_pressed_button->set_size_multiplier(1.0f);
			p_pressed_button = nullptr;
		}
		//----------------------------------------------------------------------------------

		//	Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//	DRAW BUTTONS
		for (auto &button : buttons)
		{
			button.draw_button(font, font_offset);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	//	De-Initialization
	//--------------------------------------------------------------------------------------
	// Unload, delete, derefeence my own stuff
	UnloadFont(font);
	p_pressed_button = nullptr;
	delete p_pressed_button;
	//
	CloseWindow(); // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}