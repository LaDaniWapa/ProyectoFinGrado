//
// Created by daniela on 7/8/24.
//

#ifndef TEAM_H
#define TEAM_H

#include "ScreenManager.h"

class Team final : public Screen {
   private:
    const char* msg = "Team Screen";

   public:
    void Load() override;
    void Unload() override;
    void Update() override;
    void Draw() override;
};

#endif  // TEAM_H
