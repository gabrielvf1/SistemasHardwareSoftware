#include "raylib.h"
int main()
{
// Initialization
//--------------------------------------------------------------------------------------
int screenWidth = 800;
int screenHeight = 450;
InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel");
int boxPositionY = screenHeight/2;
SetTargetFPS(60);
// Main game loop
while (!WindowShouldClose())
{
BeginDrawing();
// Detect window close button or ESC key
ClearBackground(RAYWHITE);
DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, MAROON);
DrawText("Texto teste!", 10, 10, 20, GRAY);
EndDrawing();
//----------------------------------------------------------------------------------
}
// De-Initialization
//--------------------------------------------------------------------------------------
CloseWindow();
// Close window and OpenGL context
//--------------------------------------------------------------------------------------
return 0;
}