//
// Created by daniela on 7/4/24.
//

#include "ScreenManager.h"

void Screen::SetScreenManager(ScreenManager* manager) {
    this->screenManager = manager;
}
void Screen::SetData(const std::string& key, const void* data) {
    this->screenData[key] = data;
}

const void* Screen::GetData(const std::string& key) const {
    // Obtener un puntero hacia los datos
    const auto it = screenData.find(key);

    // Si el puntero apunta dentro del mapa, devolver los datos
    // "second" porque el iterador devuelve un par clave-valor, entonces devolvemos el valor
    return (it != screenData.end()) ? it->second : nullptr;
}

void ScreenManager::AddScreen(const char* name, Screen* screen) {
    this->screens[name] = screen;
}

void ScreenManager::ChangeScreen(const char* name) {
    if (this->currentScreen) {
        currentScreen->Unload();
    }

    auto it = this->screens.find(name);
    if (it != this->screens.end()) {
        this->currentScreen = it->second;
        this->currentScreen->Load();
    }
}
void ScreenManager::Update() const {
    if (this->currentScreen) {
        this->currentScreen->Update();
    }
}

void ScreenManager::Draw() const {
    if (this->currentScreen) {
        this->currentScreen->Draw();
    }
}

Screen* ScreenManager::getScreen(const std::string& name) {
    const auto it = screens.find(name);
    return (it != this->screens.end()) ? it->second : nullptr;
}