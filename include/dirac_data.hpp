#pragma once

#include "../include/Dirac/scalar2.hpp"
#include "../include/Dirac/wavefunc2.hpp"

#include <iostream>

class DiracData
{
    public:

        DiracData();
        ~DiracData();

        DiracData(WaveFunc2* _toWaveFunc_);

        void setMax(float _max_                              );
        void evolve(float _deltaTime_, Scalar2* _toPotential_);

        uint32_t size   (                                  );
        Complex  probAmp(uint32_t _index_, uint32_t _jndex_);
        float    prob   (uint32_t _index_, uint32_t _jndex_);
        float    max    (                                  );

    private:

        WaveFunc2* _toWaveFunc;
        float      _maxProb   ;
};