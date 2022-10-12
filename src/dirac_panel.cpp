#include "../include/dirac_panel.hpp"

DiracPanel::DiracPanel()
{
    _size           = 0u           ;
    _originVertex   = Vertex()     ;
    _toWaveFunc     = new WaveFunc2;
    _toWindow       = NULL         ;
    _maxProb        = 0.0F         ;
}

DiracPanel::~DiracPanel()
{
    delete _toWaveFunc;
    
    for (uint32_t i = _size - 1u; i >= 0; i--)
        delete (&_originVertex  + i);
}

DiracPanel::DiracPanel(Vertex _originVertex_, WaveFunc2* _toWaveFunc_, Window* _toWindow_)
{
    _size           = _toWaveFunc_->size();
    _originVertex   = _originVertex_      ;
    _toWaveFunc     = _toWaveFunc_        ;
    _toWindow       = _toWindow_          ;
    _maxProb        = 0.0F                ;

    for (uint32_t i = 0u; i < _size; i++)
    {
        uint32_t x = (&_originVertex + i)->xIndex();
        uint32_t y = (&_originVertex + i)->yIndex();

        float prob = _toWaveFunc->prob(x, y);

        if (_maxProb < prob)
            _maxProb = prob;
    }
}

void DiracPanel::render()
{
    for (uint32_t i = 0u; i < _size; i++)
        (&_originVertex + i)->render(   );
}