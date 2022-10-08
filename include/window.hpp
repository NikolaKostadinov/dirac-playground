#pragma once

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

        void render(SDL_Texture* _toTexture_);

        SDL_Texture* loadTexture(const char* _path_);

    private:

        SDL_Window*   _window  ;
        SDL_Renderer* _renderer;
};