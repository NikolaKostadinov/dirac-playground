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
    Color         color    = toColor(*_toValue)   ;

    SDL_SetRenderDrawColor(
        renderer,
        color.red,
        color.green,
        color.blue,
        255
    );

    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            int x = i + xCoord();
            int y = j + yCoord();

            SDL_RenderDrawPoint(renderer, x, y);
        }
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
int Vertex<T>::xCoord()
{
    int width = _toWindow->width();
    int delta = width / SIZE_X    ;
    
    return (int) _xIndex * delta  ;
}

template <class T>
int Vertex<T>::yCoord()
{
    int height = _toWindow->height();
    int delta  = height / SIZE_Y    ;
    
    return (int) _yIndex * delta    ;
}

template <class T>
Color toColor(T _value_)
{
    float activation  = (float) _value_ * 255;
    return Color(activation, activation, activation);
}

template class Vertex<float>;