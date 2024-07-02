//
// Created by daniela on 7/2/24.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <string>

#include "raylib.h"

class AnimatedSprite {
   private:
    Texture2D texture;
    Rectangle frameRec;
    int frameCount = 0;
    int currentFrame = 0;
    int framesCounter = 0;
    const int SPEED = 8;

   public:
    AnimatedSprite(std::string pokemonName) {
        this->texture = LoadTexture(TextFormat("../assets/sprites/EBDX/Front/%s.png", pokemonName.c_str()));
        frameCount = this->texture.width / this->texture.height;
        frameRec = {.0f, .0f, static_cast<float>(this->texture.height), static_cast<float>(this->texture.height)};
    }

    ~AnimatedSprite() {
        if (this->texture.id > 0) {
            UnloadTexture(this->texture);
        }
    }

    void draw(Vector2 pos,  const int scale) {
        DrawTexturePro(
            this->texture,
            this->frameRec,
            Rectangle{pos.x, pos.y, this->frameRec.width * scale, this->frameRec.height * scale},
            Vector2{.0f, .0f}, .0f, WHITE
        );
    }

    void update() {
        this->framesCounter++;

        if (this->framesCounter >= (60 / this->SPEED)) {
            this->framesCounter = 0;
            this->currentFrame++;

            if (this->currentFrame > this->frameCount) this->currentFrame = 0;

            this->frameRec.x = static_cast<float>(this->currentFrame) * this->texture.height;
        }
    }
};

#endif  // ANIMATEDSPRITE_H
