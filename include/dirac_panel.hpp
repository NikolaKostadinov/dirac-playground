#pragma once

#include "window.hpp"

#include "../include/Dirac/wavefunc2.hpp"

class Vertex
{
    public:

        void render();

        uint32_t xIndex();
        uint32_t yIndex();
};

class DiracPanel
{
    friend class Vertex;

    public:

        DiracPanel();
        ~DiracPanel();

        DiracPanel(
            Vertex     _originVertex_,
            WaveFunc2* _toWaveFunc_  ,
            Window*    _toWindow_
        );

        void render();

    private:

        uint32_t   _size        ;
        Vertex     _originVertex;
        WaveFunc2* _toWaveFunc  ;
        Window*    _toWindow    ;
        float      _maxProb     ;
};