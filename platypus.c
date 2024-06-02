#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

#define TARGET_FPS 60
#define SQUARE_SIZE 60

int main(){
    InitWindow(800, 600, "Platypus?");
    SetTargetFPS(TARGET_FPS);
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    Color green = GetColor(0x38918FFF);
    Color orange = GetColor(0xFDB346FF);
    Color brown = GetColor(0x51280AFF);
    Color beige = GetColor(0xFCDBA8FF);

    Camera2D camera = {
        .zoom = 1.0f
    };

    Vector2 cc = {
        .x = w/2-(SQUARE_SIZE/2),
        .y = h/2-(SQUARE_SIZE/2)
    };

    Vector2 square_dimensions = {SQUARE_SIZE, SQUARE_SIZE};

    BeginMode2D(camera);

    int active = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
            if(IsKeyPressed(KEY_ENTER)){
                active = !active;
            }

            ClearBackground(GetColor(0x181818FF));

            DrawRectangleV(Vector2Subtract(cc, (Vector2) {3*SQUARE_SIZE, 0}), square_dimensions, green);
            DrawRectangleV(Vector2Subtract(cc, (Vector2) {2*SQUARE_SIZE, 0}), square_dimensions, orange);
            if(active){
                DrawRectangleV(Vector2Subtract(cc, (Vector2) {2*SQUARE_SIZE, SQUARE_SIZE}), square_dimensions, brown);
            }

            DrawRectangleV(Vector2Add(cc, (Vector2) {3*SQUARE_SIZE, 0}), square_dimensions, beige);
            DrawRectangleV(Vector2Add(cc, (Vector2) {3*SQUARE_SIZE, -SQUARE_SIZE}), square_dimensions, brown);
            Vector2 text_coords = Vector2Add(cc, (Vector2){3.8*SQUARE_SIZE, -SQUARE_SIZE});
            if(!active){
                DrawText("???", text_coords.x, text_coords.y, 40, WHITE);
            } else {
                DrawText("! ! !", text_coords.x, text_coords.y, 40, RED);
            }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
