#include "../include/window.hpp"

Window::Window(const char* _toTitle_, int _width_, int _height_) : _window(NULL), _renderer(NULL)
{
    isRunning = true;

    _window = SDL_CreateWindow(
        _toTitle_,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _width_,
        _height_,
        SDL_WINDOW_SHOWN
    );

    if (_window == NULL)
    {
        std::cout << "SDL_WINDOW ERROR: " << SDL_GetError() << std::endl;
        isRunning = false;
    }

    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
}

void Window::cleanUp()
{
    SDL_DestroyWindow(_window);
    isRunning = false;
}