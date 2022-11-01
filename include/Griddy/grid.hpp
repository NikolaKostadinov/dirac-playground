#pragma once

#include "griddy_params.h"
#include "vertex.hpp"
#include "window.hpp"

#include "./SDL2/SDL.h"

namespace GRIDDY
{
    class Grid
    {
        public:

            Grid(Window*  _toWindow_);
            virtual ~Grid();

            void setPosition(SDL_Rect _rect_     = SDL_Rect()  );
            void setSize    (
                 uint32_t _xSize_,
                 uint32_t _ySize_
            );
            void setVertices(Vertex*  _toOrigin_ = new Vertex());
            void setWindow  (Window*  _toWindow_               );
            
            void render();

            uint32_t dx();
            uint32_t dy();

        protected:

            SDL_Rect _rect    ;
            uint32_t _xSize   ;
            uint32_t _ySize   ;
            Vertex*  _toOrigin;
            Window*  _toWindow;
    };
}