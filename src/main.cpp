#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "AnimatedSprite.h"
#include "raygui.h"

int main() {
    InitWindow(960, 540, "raygui - controls test suite");
    SetTargetFPS(60);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0x0b0e26ff);
    GuiSetIconScale(2);

    const auto pkm = new AnimatedSprite("BULBASAUR");
    const auto pkm2 = new AnimatedSprite("CHARMANDER");
    const auto pkm3 = new AnimatedSprite("SQUIRTLE");

    while (!WindowShouldClose()) {
        pkm->update();
        pkm2->update();
        pkm3->update();

        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        pkm->draw(Vector2{140, 310}, 5);
        pkm2->draw(Vector2{390, 290}, 5);
        pkm3->draw(Vector2{640, 290}, 5);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}