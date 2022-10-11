#pragma once

#include "playgroundparams.h"
#include "dirac_panel.hpp"

#include "../include/Dirac/wavefunc2.hpp"
#include "../include/SDL2/SDL.h"

class Vertex
{
    public:

        Vertex();
        ~Vertex();

        Vertex(
            uint32_t    _x_           ,
            uint32_t    _y_           ,
            DiracPanel* _toDiracPanel_
        );
        
        void render();

        uint32_t xIndex();
        uint32_t yIndex();
        Complex  value ();
        int      dx    ();
        int      dy    ();
        int      xCoord();
        int      yCoord();

    private:

        uint32_t    _xIndex      ;
        uint32_t    _yIndex      ;
        DiracPanel* _toDiracPanel;
};