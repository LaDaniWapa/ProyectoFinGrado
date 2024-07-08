//
// Created by daniela on 7/4/24.
//

#ifndef TITLE_H
#define TITLE_H

#include "ScreenManager.h"

class Title final : public Screen {
   private:
    const char* msg = "Title Screen";

   public:
    void Load() override;
    void Unload() override;
    void Update() override;
    void Draw() override;
};

#endif  // TITLE_H
