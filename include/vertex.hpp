#pragma once

#include "window.hpp"

template <class T>
class Vertex
{
    public:

        Vertex(T  _value_  , unsigned int _x_, unsigned int _y_, Window* _toWindow_);
        Vertex(T* _toValue_, unsigned int _x_, unsigned int _y_, Window* _toWindow_);

        void render();

    private:

        unsigned int _xIndex  ;
        unsigned int _yIndex  ;
        T*           _toValue ;
        Window*      _toWindow;
};