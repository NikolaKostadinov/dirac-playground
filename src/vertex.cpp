#include "../include/vertex.hpp"

Vertex::Vertex()
{
    _xIndex = 0u;
    _yIndex = 0u;
}

Vertex::~Vertex()
{

}

Vertex::Vertex(uint32_t _x_, uint32_t _y_)
{
    _xIndex = _x_;
    _yIndex = _y_;
}

void Vertex::render(DiracPanel* _toDirac_)
{
    SDL_Renderer* renderer = _toDirac_->_toWindow->renderer();
    
    SDL_Rect* block = new SDL_Rect;
    block->x        = xCoord()    ;
    block->y        = yCoord()    ;
    block->w        = dx()        ;
    block->h        = dy()        ;

    float   prob  = value(_toDirac_).conjSq();
    uint8_t green = 255 * prob / _toDirac_->_maxProb;

    SDL_SetRenderDrawColor(renderer, 0, green, 0, 255);
    SDL_RenderFillRect(renderer, block);

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

Complex Vertex::value(DiracPanel* _toDirac_)
{
    return _toDirac_->_toWaveFunc->value(_xIndex, _yIndex);
}