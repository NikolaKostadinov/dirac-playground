#pragma once

#include "playgroundparams.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>

class Window
{
    public:

        bool isRunning;

        Window(const char* _toTitle_, int _width_, int _height_);

        void cleanUp();
        void display();
        void clear  ();
        
        SDL_Renderer* renderer();

    private:

        int           _width   ;
        int           _height  ;
        SDL_Window*   _window  ;
        SDL_Renderer* _renderer;
};