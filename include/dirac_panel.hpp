#pragma once

#include "vertex.hpp"
#include "window.hpp"

#include "../include/Dirac/wavefunc2.hpp"

class DiracPanel
{
    friend class Vertex;

    public:

        DiracPanel();
        ~DiracPanel();

        DiracPanel(
            Vertex*    _toOriginVertex_,
            WaveFunc2* _toWaveFunc_    ,
            Window*    _toWindow_
        );

        void render();

    private:

        uint32_t   _size          ;
        Vertex*    _toOriginVertex;
        WaveFunc2* _toWaveFunc    ;
        Window*    _toWindow      ;
        float      _maxProb       ;
};