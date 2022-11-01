#pragma once

#include "griddy_params.h"

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>

namespace GRIDDY
{
    class Window
    {
        public:

            bool isRunning;

            Window(
                const char* _title_  = DEFAULT_TITLE ,
                uint32_t    _width_  = DEFAULT_WIDTH ,
                uint32_t    _height_ = DEFAULT_HEIGHT
            );
            virtual ~Window();

            void          destroy ();
            void          display ();
            void          clear   ();
            
            uint32_t      width   ();
            uint32_t      height  ();
            SDL_Renderer* renderer();

        protected:

            uint32_t      _width   ;
            uint32_t      _height  ;
            SDL_Window*   _window  ;
            SDL_Renderer* _renderer;
    };
}