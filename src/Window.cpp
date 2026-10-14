#include "Window.h"

#include <iostream>

Window::Window(const char *title, int width, int height)
{
    m_window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_RESIZABLE);

    if (!m_window)
    {
        std::cerr << "Window creation failed: "
                  << SDL_GetError() << '\n';
        return;
    }

    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        SDL_RENDERER_ACCELERATED);

    if (!m_renderer)
    {
        std::cerr << "Renderer creation failed: "
                  << SDL_GetError() << '\n';

        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
}

Window::~Window()
{
    if (m_renderer)
        SDL_DestroyRenderer(m_renderer);

    if (m_window)
        SDL_DestroyWindow(m_window);
}

SDL_Renderer *Window::getRenderer() const
{
    return m_renderer;
}

SDL_Window *Window::getWindow() const
{
    return m_window;
}

void Window::getSize(int &width, int &height) const
{
    SDL_GetWindowSize(m_window, &width, &height);
}

void Window::clear()
{
    SDL_SetRenderDrawColor(m_renderer, 20, 20, 20, 255);
    SDL_RenderClear(m_renderer);
}

void Window::present()
{
    SDL_RenderPresent(m_renderer);
}