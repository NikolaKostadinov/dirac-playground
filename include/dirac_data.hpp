#pragma once

#include "../include/Dirac/wavefunc2.hpp"

class DiracData
{
    public:

        DiracData();
        ~DiracData();

        DiracData(WaveFunc2* _toWaveFunc_);

        void setMax(float _max_      );
        void evolve(float _deltaTime_);

        uint32_t size   (                                  );
        Complex  probAmp(uint32_t _index_, uint32_t _jndex_);
        float    prob   (uint32_t _index_, uint32_t _jndex_);
        float    max    (                                  );

    private:

        WaveFunc2* _toWaveFunc;
        float      _maxProb   ;
};