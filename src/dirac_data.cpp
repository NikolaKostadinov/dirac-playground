#include "../include/dirac_data.hpp"

DiracData::DiracData()
{
    _toWaveFunc = new WaveFunc2;
    _maxProb    = 0.0F         ;
}

DiracData::~DiracData()
{
    delete _toWaveFunc;
}

DiracData::DiracData(WaveFunc2* _toWaveFunc_)
{
    _toWaveFunc = _toWaveFunc_;
    _maxProb    = 0.0F        ;

    for (uint32_t i = 0; i < _toWaveFunc->xSize(); i++)
        for (uint32_t j = 0; j < _toWaveFunc->ySize(); j++)
        {
            float thisProb = prob(i, j);

            if (_maxProb < thisProb)
                _maxProb = thisProb;
        }
}

void DiracData::setMax(float _max_)
{
    _maxProb = _max_;
}

void DiracData::evolve(float _deltaTime_)
{
    _toWaveFunc->evolve(_deltaTime_);
}

uint32_t DiracData::size()
{
    return _toWaveFunc->size();
}

Complex DiracData::probAmp(uint32_t _index_, uint32_t _jndex_)
{
    return _toWaveFunc->probAmp(_index_, _jndex_);
}

float DiracData::prob(uint32_t _index_, uint32_t _jndex_)
{
    return _toWaveFunc->prob(_index_, _jndex_);
}

float DiracData::max()
{
    return _maxProb;
}