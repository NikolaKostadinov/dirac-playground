#include "../include/vertex.hpp"

template <class T>
Vertex<T>::Vertex()
{
    _toValue  = new T;
    _xIndex   = 0U   ;
    _yIndex   = 0U   ;
    _toWindow = NULL ;
}

template <class T>
Vertex<T>::Vertex(T _value_, unsigned int _x_, unsigned int _y_, Window* _toWindow_)
{
    _toValue  = &_value_   ;
    _xIndex   =  _x_       ;
    _yIndex   =  _y_       ;
    _toWindow =  _toWindow_;
}

template <class T>
Vertex<T>::Vertex(T* _toValue_, unsigned int _x_, unsigned int _y_, Window* _toWindow_)
{
    _toValue  = _toValue_ ;
    _xIndex   = _x_       ;
    _yIndex   = _y_       ;
    _toWindow = _toWindow_;
}

template <class T>
void Vertex<T>::render()
{
    SDL_Renderer* renderer = _toWindow->renderer();
    Color         color    = toColor<T>(*_toValue);
    
    SDL_Rect block;
    block.x = xCoord();
    block.y = yCoord();
    block.w = dx();
    block.h = dy();

    SDL_SetRenderDrawColor(
        renderer,
        color.red,
        color.green,
        color.blue,
        255
    );

    SDL_RenderFillRect(renderer, &block);
}

template <class T>
unsigned int Vertex<T>::xIndex()
{
    return _xIndex;
}

template <class T>
unsigned int Vertex<T>::yIndex()
{
    return _yIndex;
}

template <class T>
int Vertex<T>::dx()
{
    return _toWindow->width() / SIZE_X;
}

template <class T>
int Vertex<T>::dy()
{
    return _toWindow->height() / SIZE_Y;
}

template <class T>
int Vertex<T>::xCoord()
{
    return (int) _xIndex * dx();
}

template <class T>
int Vertex<T>::yCoord()
{
    return (int) _yIndex * dy();
}

template <class T>
Color toColor(T _value_)
{
    unsigned char red = _value_;
    return Color(red, 0, 0);
}

template class Vertex<float>;