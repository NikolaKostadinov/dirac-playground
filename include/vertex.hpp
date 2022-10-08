#pragma once

#include "playgroundparams.h"
#include "color.h"
#include "window.hpp"

#include "../include/Dirac/complex.hpp"
#include "../include/SDL2/SDL.h"
#include <type_traits>

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

Color toColor(float _value_);
Color toColor(Complex _value_);