#pragma once

#include "griddy_params.h"
#include "color.h"

#include "../include/SDL2/SDL.h"

namespace GRIDDY
{
    class Vertex
    {
        public:

            Vertex(
                uint32_t _index_ = 0u,
                uint32_t _jndex_ = 0u
            );
            virtual ~Vertex();
            
            void setColor(color  _color_);
            void moveTo(uint32_t _index_, uint32_t _jndex_);
            void render(SDL_Rect* _rect_, SDL_Renderer* _renderer_);

            uint32_t  index();
            uint32_t  jndex();
            uint32_t xCoord();
            uint32_t yCoord();

        protected:

            uint32_t _xIndex;
            uint32_t _yIndex;
            color    _color ;
    };
}