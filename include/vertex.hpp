#pragma once

#include "playgroundparams.h"
#include "dirac_panel.hpp"

#include "../include/SDL2/SDL.h"

class Vertex
{
    public:

        Vertex();
        ~Vertex();

        Vertex(
            uint32_t _x_,
            uint32_t _y_
        );
        
        void render(DiracPanel* _toDirac_);

        uint32_t xIndex();
        uint32_t yIndex();
        int      dx    ();
        int      dy    ();
        int      xCoord();
        int      yCoord();
        
        Complex  value(DiracPanel* _toDirac_);

    private:

        uint32_t _xIndex;
        uint32_t _yIndex;
};