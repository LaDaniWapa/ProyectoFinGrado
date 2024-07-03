//
// Created by daniela on 7/3/24.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(const char* pokemonName) {
    this->texture = LoadTexture(TextFormat("assets/sprites/EBDX/Front/%s.png", pokemonName));
    frameCount = this->texture.width / this->texture.height;
    frameRec = {.0f, .0f, static_cast<float>(this->texture.height), static_cast<float>(this->texture.height)};
}

AnimatedSprite::~AnimatedSprite() {
    UnloadTexture(this->texture);
}
void AnimatedSprite::draw(const Vector2 &pos, const int scale) {
    DrawTexturePro(
        this->texture,
        this->frameRec,
        Rectangle{pos.x, pos.y, this->frameRec.width * scale, this->frameRec.height * scale},
        Vector2{.0f, .0f},
        .0f,
        WHITE);
}
void AnimatedSprite::update() {
    this->framesCounter++;

    if (this->framesCounter >= (60 / this->SPEED)) {
        this->framesCounter = 0;
        this->currentFrame++;

        if (this->currentFrame > this->frameCount) this->currentFrame = 0;

        this->frameRec.x = static_cast<float>(this->currentFrame) * this->texture.height;
    }
}
