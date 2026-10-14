#pragma once
#include <SDL2/SDL.h>

class Window
{
public:
    Window(const char *title, int width, int height);
    ~Window();

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    SDL_Renderer *getRenderer() const;
    SDL_Window *getWindow() const;

    void getSize(int &width, int &height) const;
    void clear();
    void present();

private:
    SDL_Window *m_window = nullptr;
    SDL_Renderer *m_renderer = nullptr;
};