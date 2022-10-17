#pragma once

#include "../include/Dirac/wavefunc2.hpp"

class DiracData
{
    public:

        DiracData();
        ~DiracData();

        DiracData(WaveFunc2* _toWaveFunc_);

        void evolve(float _deltaTime_);

        Complex probAmp(uint32_t _xIndex_, uint32_t _yIndex_);
        float   prob   (uint32_t _xIndex_, uint32_t _yIndex_);

    private:

        WaveFunc2* _toWaveFunc;
        float      _maxProb   ;
};