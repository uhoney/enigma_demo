#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "m_button.h"
#include <list>

int main(void)
{
	// Aakkokstaulukko nappeja varten
	// char teksti[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char teksti[] = "ABC";

	std::list<M_button> napit;

	// Luo napit aakkosista
	for (auto& kirjain : teksti)
	{
		M_button nappi = M_button(kirjain);
		napit.emplace_back(nappi);
		
	}
	// Poista viimenen nappi ( == '\0')
	napit.pop_back();

	// Tulosta napit
	for (auto& nappi : napit)
	{
		TraceLog(LOG_INFO, "Nappulan kirjain on: %c", nappi.get_label());
		TraceLog(LOG_INFO, "Nappulan kirjain GUI:lle on: %c", *(nappi.get_char_for_GUI()));
	}


 //   // Initialization
 //   //--------------------------------------------------------------------------------------
 //   const int screenWidth = 800;
 //   const int screenHeight = 450;

 //   InitWindow(screenWidth, screenHeight, "Testauksia...");

 //   // Fonttihommat
	//GetFontDefault();

 //   
 //   
 //   Vector2 ballPosition = { 100.0f, 100.0f };

 //   SetTargetFPS(30);

 //   // Main game loop
 //   while (!WindowShouldClose())    // Detect window close button or ESC key
 //   {
 //       // Update
 //       //----------------------------------------------------------------------------------


 //       //----------------------------------------------------------------------------------

 //       // Draw
 //       //----------------------------------------------------------------------------------
 //       BeginDrawing();
 //       ClearBackground(RAYWHITE);

 //       
 //       // Text
 //       //DrawText(teksti, 190, 200, 20, BLACK);

 //       EndDrawing();
 //       //----------------------------------------------------------------------------------
 //   }

 //   // De-Initialization
 //   //--------------------------------------------------------------------------------------
 //   CloseWindow();        // Close window and OpenGL context
 //   //--------------------------------------------------------------------------------------

    return 0;
}