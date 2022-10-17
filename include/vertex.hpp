#pragma once

#include "playgroundparams.h"
#include "window.hpp"
#include "dirac_data.hpp"

#include "../include/Dirac/wavefunc2.hpp"
#include "../include/SDL2/SDL.h"

class Vertex
{
    public:

        Vertex();
        ~Vertex();

        Vertex(uint32_t _index_, uint32_t _jndex_);
        
        void render(
            DiracData*   _toDiracData_,
            SDL_Renderer* _toRenderer_
        );

        uint32_t xIndex();
        uint32_t yIndex();
        int      dx    ();
        int      dy    ();
        int      xCoord();
        int      yCoord();
        
        Complex  probAmp(DiracData* _toDiracData_);
        float    prob   (DiracData* _toDiracData_);

    private:

        uint32_t _xIndex;
        uint32_t _yIndex;
};