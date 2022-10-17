#include "../include/vertex.hpp"

Vertex::Vertex()
{
    _xIndex = 0u;
    _yIndex = 0u;
}

Vertex::~Vertex()
{

}

Vertex::Vertex(uint32_t _index_, uint32_t _jndex_)
{
    _xIndex = _index_;
    _yIndex = _jndex_;
}

void Vertex::render(DiracData* _toDiracData_, SDL_Renderer* _toRenderer_)
{
    SDL_Rect* block = new SDL_Rect;
    block->x        = xCoord()    ;
    block->y        = yCoord()    ;
    block->w        = dx()        ;
    block->h        = dy()        ;

    float   thisProb  = prob(_toDiracData_)                  ;
    uint8_t green     = 255 * thisProb / _toDiracData_->max();

    SDL_SetRenderDrawColor(_toRenderer_, 0, green, 0, 255);
    SDL_RenderFillRect(_toRenderer_, block)               ;

    delete block;
}

uint32_t Vertex::xIndex()
{
    return _xIndex;
}

uint32_t Vertex::yIndex()
{
    return _yIndex;
}

int Vertex::dx()
{
    return SIM_WIDTH / SIZE_X;
}

int Vertex::dy()
{
    return SIM_HEIGHT / SIZE_Y;
}

int Vertex::xCoord()
{
    return (int) _xIndex * dx() + SIM_XPOS;
}

int Vertex::yCoord()
{
    return (int) _yIndex * dy() + SIM_YPOS;
}

Complex Vertex::probAmp(DiracData* _toDiracData_)
{
    return _toDiracData_->probAmp(_xIndex, _yIndex);
}

float Vertex::prob(DiracData* _toDiracData_)
{
    return _toDiracData_->prob(_xIndex, _yIndex);
}