#include "../include/vertex.hpp"

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
    
}

template class Vertex<float>;