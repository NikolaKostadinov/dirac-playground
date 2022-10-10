#include "../include/vertex.hpp"

Vertex::Vertex()
{
    _xIndex     = 0U           ;
    _yIndex     = 0U           ;
    _toWaveFunc = new WaveFunc2;
    _toWindow   = NULL         ;
    _maxProb    = 0.0F         ;
}

Vertex::~Vertex()
{
    delete _toWaveFunc;
    delete _toWindow  ;
}

Vertex::Vertex(uint32_t _x_, uint32_t _y_, WaveFunc2* _toWaveFunc_, Window* _toWindow_)
{
    _xIndex     = _x_         ;
    _yIndex     = _y_         ;
    _toWaveFunc = _toWaveFunc_;
    _toWindow   = _toWindow_  ;

    _maxProb = 0.0F;
    for (uint16_t i = 0u; i < _toWaveFunc->xSize(); i++)
        for (uint16_t j = 0u; j < _toWaveFunc->ySize(); j++)
            {
                float prob = _toWaveFunc->prob(i, j);
                if (prob > _maxProb) _maxProb = prob;
            }
}

void Vertex::render()
{
    SDL_Renderer* renderer = _toWindow->renderer();
    
    SDL_Rect* block = new SDL_Rect;
    block->x        = xCoord()    ;
    block->y        = yCoord()    ;
    block->w        = dx()        ;
    block->h        = dy()        ;

    float   prob  = value().conjSq();
    uint8_t green = 314159 * prob;

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
    return _toWindow->width() / SIZE_X;
}

int Vertex::dy()
{
    return _toWindow->height() / SIZE_Y;
}

int Vertex::xCoord()
{
    return (int) _xIndex * dx();
}

int Vertex::yCoord()
{
    return (int) _yIndex * dy();
}

Complex Vertex::value()
{
    return _toWaveFunc->value(_xIndex, _yIndex);
}