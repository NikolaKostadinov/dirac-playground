#pragma once

#include "vertex.hpp"
#include "window.hpp"
#include "dirac_data.hpp"

#include "../include/Dirac/scalar2.hpp"

class DiracPanel
{
    public:

        DiracPanel();
        ~DiracPanel();

        DiracPanel(
            Vertex*    _toOriginVertex_,
            Window*    _toWindow_      ,
            DiracData* _toDiracData_
        );

        void evolve(float _deltaTime_, Scalar2* _toPotential);
        void render(                                        );

        uint32_t size();

    private:

        Vertex*    _toOriginVertex;
        Window*    _toWindow      ;
        DiracData* _toDiracData   ;
};