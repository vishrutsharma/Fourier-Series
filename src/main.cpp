#include <SDL2/SDL.h>

#include "Application.h"

#include <iostream>

int main(int argc, char *argv[])
{
    SDL_SetMainReady();

    Application application;

    if (!application.initialize())
    {
        return 1;
    }

    application.run();

    SDL_Quit();

    return 0;
}