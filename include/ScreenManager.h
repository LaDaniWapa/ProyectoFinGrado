//
// Created by daniela on 7/4/24.
//

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <string>
#include <unordered_map>
#include <raylib.h>

class ScreenManager;

/**
 * Representa una pantalla en el juego, en la que se dibujan los elementos
 */
class Screen {
   protected:
    /**
     * Administrador de pantallas
     */
    ScreenManager* screenManager = nullptr;

    /**
     * Datos de la pantalla
     */
    std::unordered_map<std::string, const void*> screenData;

   public:
    /**
     * Destructor por defecto
     */
    virtual ~Screen() = default;

    /**
     * Cargar las variables necesarias para la pantalla
     */
    virtual void Load() = 0;

    /**
     * Descargar las variables que ya no serán necesarias
     */
    virtual void Unload() = 0;

    /**
     * Actualizar la pantalla
     */
    virtual void Update() = 0;

    /**
     * Dibujar la pantalla
     */
    virtual void Draw() = 0;

    /**
     * Establecer el administrador de pantallas para la clase derivada
     * @param manager Administrador
     */
    void SetScreenManager(ScreenManager* manager);

    /**
     * Establecer datos para ser pasados entre pantallas
     * @param key Key donde guardar los datos
     * @param data Los datos
     */
    void SetData(const std::string& key, const void* data);

    /**
     * Obtener datos entre pantallas
     * @param key Key donde se guardaron los datos
     * @return Los datos guardados
     */
    const void* GetData(const std::string& key) const;
};

/**
 * Administrador de pantallas del juego
 */
class ScreenManager {
    /**
     * Mapa de pantallas
     */
    std::unordered_map<std::string, Screen*> screens;

    /**
     * Puntero hacia la pantalla actual
     */
    Screen* currentScreen = nullptr;

   public:
    /**
     * Añadir una pantalla al administrador
     * @param name Nombre de la pantalla
     * @param screen Puntero hacia la pantalla
     */
    void AddScreen(const char* name, Screen* screen);

    /**
     * Cambiar la pantalla actual
     * @param name Nombre de la nueva pantalla
     */
    void ChangeScreen(const char* name);

    /**
     * Actualizar la pantalla actual
     */
    void Update() const;

    /**
     * Dibujar la pantalla actual
     */
    void Draw() const;

    /**
     * Devuelve la pantalla actual
     * @param name Nombre de la pantalla
     * @return Puntero hacia la pantalla
     */
    Screen* getScreen(const std::string& name);
};

#endif  // SCREENMANAGER_H
