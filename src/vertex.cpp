#include "../include/vertex.hpp"

Vertex::Vertex()
{
    _xIndex       = 0u            ;
    _yIndex       = 0u            ;
    _toDiracPanel = new DiracPanel;
}

Vertex::~Vertex()
{
    delete _toDiracPanel;
}

Vertex::Vertex(uint32_t _x_, uint32_t _y_, DiracPanel* _toDiracPanel_)
{
    _xIndex       = _x_           ;
    _yIndex       = _y_           ;
    _toDiracPanel = _toDiracPanel_;
}

void Vertex::render()
{
    SDL_Renderer* renderer = _toDiracPanel->_toWindow->renderer();
    
    SDL_Rect* block = new SDL_Rect;
    block->x        = xCoord()    ;
    block->y        = yCoord()    ;
    block->w        = dx()        ;
    block->h        = dy()        ;

    float   prob  = value().conjSq();
    uint8_t green = 255 * prob / _toDiracPanel->_maxProb;

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

Complex Vertex::value()
{
    return _toDiracPanel->_toWaveFunc->value(_xIndex, _yIndex);
}