//
// Created by daniela on 7/8/24.
//

#include "Team.h"

#include <UI.h>

void Team::Load() {}
void Team::Unload() {}
void Team::Update() {
    if (IsKeyPressed(KEY_ENTER)) {
        screenManager->ChangeScreen("title");
    }
}
void Team::Draw() {
    UI::DrawRectangleWithBorders(Rectangle{10, 10, 200, 30});
    DrawText(msg, 17, 15, 10, WHITE);
}
