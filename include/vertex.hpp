#pragma once

#include "playgroundparams.h"
#include "window.hpp"

#include "../include/Dirac/WaveFunc2.hpp"
#include "../include/SDL2/SDL.h"

class Vertex
{
    public:

        Vertex();
        virtual ~Vertex();

        Vertex(
            uint32_t   _x_         ,
            uint32_t   _y_         ,
            WaveFunc2* _toWaveFunc_,
            Window*    _toWindow_
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

        uint32_t   _xIndex    ;
        uint32_t   _yIndex    ;
        WaveFunc2* _toWaveFunc;
        Window*    _toWindow  ;
        float      _maxProb   ;
};