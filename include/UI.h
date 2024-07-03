//
// Created by daniela on 7/3/24.
//

#ifndef UI_H
#define UI_H
#include "raylib.h"

namespace UI {
// Tamaño de las esquinas
constexpr float cornerSize = 8.f;

/**
 * Inicializa las texturas necesarias
 */
void Init();

/**
 * Descarga de memoria las texturas
 */
void Cleanup();

/* Extern le dice al compilador que esta variable existe, pero que está definida en otro archivo */

// Textura de los bordes
extern Texture2D border;

/**
 * Dibuja un rectangulo con bordes cargados de una imagen
 * @param bounds Tamaño y posicion del rectángulo
 */
void DrawRectangleWithBorders(const Rectangle &bounds);
}  // namespace UI
#endif  // UI_H