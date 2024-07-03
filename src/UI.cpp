//
// Created by daniela on 7/3/24.
//

#include "UI.h"

namespace UI {
Texture2D border; // Obtener la variable del header

void Init() {
    border = LoadTexture("assets/window_1.png");
}

void Cleanup() {
    UnloadTexture(border);
}

void DrawRectangleWithBorders(const Rectangle& bounds) {
    // Esquina superior izquierda
    DrawTexturePro(
        border,
        Rectangle{0, 0, cornerSize, cornerSize},
        Rectangle{bounds.x, bounds.y, cornerSize, cornerSize},
        Vector2{.0f, .0f},
        .0f,
        WHITE);

    // Esquina superior derecha
    DrawTexturePro(
        border,
        Rectangle{border.width - cornerSize, 0, cornerSize, cornerSize},
        Rectangle{bounds.x + bounds.width - cornerSize, bounds.y, cornerSize, cornerSize},
        Vector2{.0f, .0f},
        .0f,
        WHITE);

    // Esquina inferior izquierda
    DrawTexturePro(
        border,
        Rectangle{0, border.height - cornerSize, cornerSize, cornerSize},
        Rectangle{bounds.x, bounds.y + bounds.height - cornerSize, cornerSize, cornerSize},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Esquina inferior derecha
    DrawTexturePro(
        border,
        Rectangle{border.width - cornerSize, border.height - cornerSize, cornerSize, cornerSize},
        Rectangle{bounds.x + bounds.width - cornerSize, bounds.y + bounds.height - cornerSize, cornerSize, cornerSize},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Lado de arriba
    DrawTexturePro(
        border,
        Rectangle{cornerSize, 0, cornerSize, cornerSize},
        Rectangle{bounds.x + cornerSize, bounds.y, bounds.width - cornerSize * 2, cornerSize},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Lado de abajo
    DrawTexturePro(
        border,
        Rectangle{cornerSize, border.height - cornerSize, cornerSize, cornerSize},
        Rectangle{
            bounds.x + cornerSize, bounds.y + bounds.height - cornerSize, bounds.width - cornerSize * 2, cornerSize},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Lado izquierdo
    DrawTexturePro(
        border,
        Rectangle{0, cornerSize, cornerSize, cornerSize},
        Rectangle{bounds.x, bounds.y + cornerSize, cornerSize, bounds.height - cornerSize * 2},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Lado derecho
    DrawTexturePro(
        border,
        Rectangle{border.width - cornerSize, cornerSize, cornerSize, cornerSize},
        Rectangle{
            bounds.x + bounds.width - cornerSize, bounds.y + cornerSize, cornerSize, bounds.height - cornerSize * 2},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);

    // Centro
    DrawTexturePro(
        border,
        Rectangle{cornerSize, cornerSize, cornerSize, cornerSize},
        Rectangle{
            bounds.x + cornerSize,
            bounds.y + cornerSize,
            bounds.width - cornerSize * 2,
            bounds.height - cornerSize * 2},
        Vector2{0.f, 0.f},
        0.f,
        WHITE);
}
}  // namespace UI
