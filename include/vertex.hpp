#pragma once

#include "playgroundparams.h"
#include "color.h"
#include "window.hpp"
#include "../include/SDL2/SDL.h"

template <class T>
class Vertex
{
    public:

        Vertex();
        //~Vertex();

        Vertex(T  _value_  , unsigned int _x_, unsigned int _y_, Window* _toWindow_);
        Vertex(T* _toValue_, unsigned int _x_, unsigned int _y_, Window* _toWindow_);
        
        void render();

        unsigned int xIndex();
        unsigned int yIndex();
        signed   int dx    ();
        signed   int dy    ();
        signed   int xCoord();
        signed   int yCoord();

    private:

        unsigned int _xIndex  ;
        unsigned int _yIndex  ;
        T*           _toValue ;
        Window*      _toWindow;
};

template <class T>
Color toColor(T _value_);