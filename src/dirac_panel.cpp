#include "../include/dirac_panel.hpp"

DiracPanel::DiracPanel()
{
    _size           = 0u           ;
    _toOriginVertex = new Vertex   ;
    _toWaveFunc     = new WaveFunc2;
    _toWindow       = NULL         ;
    _maxProb        = 0.0F         ;
}

DiracPanel::~DiracPanel()
{
    delete _toWaveFunc;
    
    for (uint32_t i = _size - 1u; i >= 0; i--)
        delete (_toOriginVertex + i);
}

DiracPanel::DiracPanel(Vertex* _toOriginVertex_, WaveFunc2* _toWaveFunc_, Window* _toWindow_)
{
    _size           = _toWaveFunc_->size();
    _toOriginVertex = _toOriginVertex_    ;
    _toWaveFunc     = _toWaveFunc_        ;
    _toWindow       = _toWindow_          ;
    _maxProb        = 0.0F                ;

    for (uint32_t i = 0u; i < _size; i++)
    {
        uint32_t x = (_toOriginVertex + i)->xIndex();
        uint32_t y = (_toOriginVertex + i)->yIndex();

        float prob = _toWaveFunc->prob(x, y);

        if (_maxProb < prob)
            _maxProb = prob;
    }
}

void DiracPanel::render()
{
    for (uint32_t i = 0u; i < _size; i++)
        (_toOriginVertex + i)->render(  );
}