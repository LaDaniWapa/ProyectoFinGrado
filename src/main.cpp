#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include <UI.h>

#include "AnimatedSprite.h"
#include "ScreenManager.h"
#include "Title.h"
#include "Team.h"
#include "raygui.h"

void initDisplays() {}

int main() {
    // Tamaños de la pantalla real y la pantalla virtual
    constexpr int screenWidth = 960;
    constexpr int screenHeight = 540;
    constexpr int virtualScreenWidth = 320;
    constexpr int virtualScreenHeight = 180;

    // Escala entre la pantalla virtual y la pantalla real
    constexpr float escala = static_cast<float>(screenWidth) / static_cast<float>(virtualScreenWidth);
    // ASpect ratio de la pantalla real
    constexpr float originalAspectRatio = static_cast<float>(screenWidth) / static_cast<float>(screenHeight);

    // Iniciar ventana
    InitWindow(screenWidth, screenHeight, "PokemonJogo <3");
    // Hacer que se pueda cambiar su tamaño
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    // Bloquear los FPS a 60
    SetTargetFPS(60);

    // Inicializar la interfaz
    UI::Init();

    // Cambiar el background-color
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0x0b0e26ff);

    // Camara de la pantalla vitual
    Camera2D worldSpaceCamera = {0};
    worldSpaceCamera.zoom = 1;

    // Camara de la pantalla real
    Camera2D screenSpaceCamera = {0};
    screenSpaceCamera.zoom = 1;

    // Canvas donde pintar las cosas (tamaño de la pantalla virtual)
    const RenderTexture2D target = LoadRenderTexture(virtualScreenWidth, virtualScreenHeight);

    // Rectangulo para pintar el canvas, es necesario que la altura este inverida
    const Rectangle sourceRec = {
        0.0f, 0.0f, static_cast<float>(target.texture.width), -static_cast<float>(target.texture.height)};
    Rectangle destRec = {-escala, -escala, screenWidth + (escala * 2), screenHeight + (escala * 2)};

    // ------ Screens ------
    ScreenManager screenManager;

    Title titleScreen;
    titleScreen.SetScreenManager(&screenManager);
    screenManager.AddScreen("title", &titleScreen);

    Team teamScreen;
    teamScreen.SetScreenManager(&screenManager);
    screenManager.AddScreen("team", &teamScreen);

    screenManager.ChangeScreen("title");
    // ------ Screens ------

    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            // Obtener nuevo tamaño de l aventana
            const int newWidth = GetScreenWidth();
            const int newHeight = GetScreenHeight();

            // Calcular el aspect retio nuevo
            const float newAspectRatio = static_cast<float>(newWidth) / static_cast<float>(newHeight);

            // Calcular la escala en comparacion de los valores nuevos a los originales
            float widthScale = static_cast<float>(newWidth) / static_cast<float>(screenWidth);
            float heightScale = static_cast<float>(newHeight) / static_cast<float>(screenHeight);

            // Si el nuevo aspect ratio es mas grande
            if (newAspectRatio > originalAspectRatio) {
                // Escalamos en vase a la altura
                widthScale = heightScale;
            } else {
                // Si no, escalamos en base al ancho
                heightScale = widthScale;
            }

            // Calcular cuanto margen hay que dejar para centrar la imagen
            const float marginX = (newWidth - screenWidth * widthScale) / 2;
            const float marginY = (newHeight - screenHeight * heightScale) / 2;

            // Actualizar el recuadro donde se va a pintar nuestra pantalla virtual
            destRec =
                Rectangle{-escala + marginX, -escala + marginY, screenWidth * widthScale, screenHeight * heightScale};
        }

        // Escalar la pantalla virtual a la pantalla real
        worldSpaceCamera.target.x = truncf(screenSpaceCamera.target.x);
        screenSpaceCamera.target.x -= worldSpaceCamera.target.x;
        screenSpaceCamera.target.x *= escala;

        worldSpaceCamera.target.y = truncf(screenSpaceCamera.target.y);
        screenSpaceCamera.target.y -= worldSpaceCamera.target.y;
        screenSpaceCamera.target.y *= escala;

        BeginTextureMode(target);  // Dibujar en el canvas
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        BeginMode2D(worldSpaceCamera);  // Dibujar en la pantalla virtual
        screenManager.Update();
        screenManager.Draw();

        DrawFPS(290, 10);

        //

        EndMode2D();       // FIN Dibujar en la pantalla virtual
        EndTextureMode();  // FIN Dibujar en el canvas

        BeginDrawing();  // Dibujar en la pantalla real

        BeginMode2D(screenSpaceCamera);  // Dibujar en el area de la pantalla real
        DrawTexturePro(target.texture, sourceRec, destRec, Vector2{.0f, .0f}, .0f, WHITE);
        EndMode2D();  // FIN Dibujar en el area de la pantalla real

        EndDrawing();  // FIN Dibujar en la pantalla real
    }

    // Descargar la interfaz
    UI::Cleanup();
    CloseWindow();

    return EXIT_SUCCESS;
}
