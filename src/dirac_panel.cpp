#include "../include/dirac_panel.hpp"

DiracPanel::DiracPanel()
{
    _toOriginVertex = new Vertex   ;
    _toWindow       = NULL         ;
    _toDiracData    = new DiracData;
}

DiracPanel::~DiracPanel()
{
    delete _toDiracData;
    
    for (uint32_t i = size() - 1u; i >= 0; i--)
        delete (_toOriginVertex  + i);
}

DiracPanel::DiracPanel(Vertex* _toOriginVertex_, Window* _toWindow_, DiracData* _toDiracData_)
{
    _toOriginVertex = _toOriginVertex_;
    _toWindow       = _toWindow_      ;
    _toDiracData    = _toDiracData_   ;
}

void DiracPanel::evolve(float _deltaTime_)
{
    _toDiracData->evolve(_deltaTime_);
}

void DiracPanel::render()
{
    SDL_Renderer* renderer = _toWindow->renderer();

    for (uint32_t i = 0u;  i < size(); i++)
    {
        Vertex* thisVertex = _toOriginVertex + i  ;
        thisVertex->render(_toDiracData, renderer);

        float thisProb = thisVertex->prob(_toDiracData);

        if (_toDiracData->max() < thisProb)
            _toDiracData->setMax( thisProb);

    }
}

uint32_t DiracPanel::size()
{
    return _toDiracData->size();
}