#include "../include/window.hpp"

Window::Window(const char* _toTitle_, int _width_, int _height_) : _window(NULL), _renderer(NULL)
{
    isRunning = true;

    _width  = _width_ ;
    _height = _height_;

    _window = SDL_CreateWindow(
        _toTitle_,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _width,
        _height,
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
    SDL_DestroyWindow  (_window  );
    SDL_DestroyRenderer(_renderer);
    isRunning = false;
}

void Window::display()
{
    SDL_RenderPresent(_renderer);
}

void Window::clear()
{
    SDL_RenderClear(_renderer);
}

/*void Window::draw()
{
    int deltaX = _width  / SIZE_X;
    int deltaY = _height / SIZE_Y;

    for (int i = 0; i < _width; i++)
        for (int j = 0; j < _height; j++)
        {
            if      (i % deltaX == 0) SDL_SetRenderDrawColor(_renderer, 55, 0, 55, 255);
            else if (j % deltaY == 0) SDL_SetRenderDrawColor(_renderer, 55, 0, 55, 255);
            else                      SDL_SetRenderDrawColor(_renderer,  0, 0,  0, 255);
            SDL_RenderDrawPoint(_renderer, i, j);
        }
}*/

int Window::width()
{
    return _width;
}

int Window::height()
{
    return _height;
}

SDL_Renderer* Window::renderer()
{
    return _renderer;
}