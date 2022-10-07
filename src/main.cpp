#define SDL_MAIN_HANDLED

#include "../include/Dirac/dirac.h"
#include "../include/SDL2/SDL.h"
#include <iostream>

#include "../include/window.hpp"

#define WINDOW_TITLE    "Hello There!"
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_INIT_VIDEO ERROR: " << SDL_GetError() << std::endl;

    Window window = Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Event event;

    while (window.isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) window.cleanUp();
        }
    }

    SDL_Quit();
    return 0;
}