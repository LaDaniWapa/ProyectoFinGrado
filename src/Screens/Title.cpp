//
// Created by daniela on 7/4/24.
//

#include "Title.h"

#include <UI.h>

void Title::Load() {}
void Title::Unload() {}
void Title::Update() {
    if (IsKeyPressed(KEY_ENTER)) {
        screenManager->ChangeScreen("team");
    }
}
void Title::Draw() {
    UI::DrawRectangleWithBorders(Rectangle{10, 10, 200, 30});
    DrawText(msg, 17, 15, 10, WHITE);
    DrawText(msg, 17, 25, 10, WHITE);
}
