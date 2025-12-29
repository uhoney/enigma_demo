#include "raylib.h"
#include <iostream>
#include "reflector.h"
#include "m_button.h"
#include <vector>

int main(void)
{
	// // Aakkokstaulukko nappeja varten
	// char teksti[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// char aakkoslista[] = "ABC";

	std::vector<M_button> buttons{M_button::create_all_buttons()};

	for (auto& button : buttons)
	{
		TraceLog(LOG_INFO, "Nappulan kirjain on: %c", button.get_label());
		// TraceLog(LOG_INFO, "Nappulan kirjain GUI:lle on: %c", *(button.get_char_for_GUI()));
		
		
	}
	// // Luo napit aakkosista
	// for (auto& kirjain : aakkoslista)
	// {
	// 	M_button nappi = M_button(kirjain);
	// 	napit.emplace_back(nappi);	
	// }
	// // Poista viimenen nappi ( == '\0')
	// napit.pop_back();

	// // Tulosta napit
	// for (auto& nappi : napit)
	// {
	// 	TraceLog(LOG_INFO, "Nappulan kirjain on: %c", nappi.get_label());
	// 	// TraceLog(LOG_INFO, "Nappulan kirjain GUI:lle on: %c", *(nappi.get_char_for_GUI()));
	// }




   // Initialization
   //--------------------------------------------------------------------------------------
   const int screenWidth = 800;
   const int screenHeight = 450;

   InitWindow(screenWidth, screenHeight, "Testauksia...");

   // Fonttihommat - default font
	GetFontDefault();


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


	//    BUTTONS
	for (auto& button : buttons)
	{
		   DrawCircleV({ button.get_position() }, 30.0f, LIGHTGRAY);
		   DrawCircleV({ button.get_position() }, 25.0f, DARKGRAY);
	}    
	
	//    Text
    //    DrawText(nappi_a.get_char_for_GUI(), ballPosition.x, ballPosition.y, 40, WHITE);


       EndDrawing();
       //----------------------------------------------------------------------------------
   }

   // De-Initialization
   //--------------------------------------------------------------------------------------
   CloseWindow();        // Close window and OpenGL context
   //--------------------------------------------------------------------------------------

    return 0;
}