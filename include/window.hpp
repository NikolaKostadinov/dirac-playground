#pragma once

#include "../include/SDL2/SDL.h"
#include <iostream>

class Window
{
    public:

        bool isRunning;

        Window(const char* _toTitle_, int _width_, int _height_);

        void cleanUp();

    private:

        SDL_Window*   _window  ;
        SDL_Renderer* _renderer;
};