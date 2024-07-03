//
// Created by daniela on 7/2/24.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "raylib.h"

class AnimatedSprite {
   private:
    Texture2D texture{};
    Rectangle frameRec{};
    int frameCount = 0;
    int currentFrame = 0;
    int framesCounter = 0;
    const int SPEED = 8;

   public:
    explicit AnimatedSprite(const char* pokemonName);
    ~AnimatedSprite();

    // TODO Añadir el parametro origin
    /**
     * Dibuja el sprite
     * @param pos Posicion del sprite
     * @param scale Escala del sprite para multiplicar su tamaño
     */
    void draw(const Vector2& pos, int scale);

    /**
     * Actualiza el sprite
     */
    void update();
};

#endif  // ANIMATEDSPRITE_H
