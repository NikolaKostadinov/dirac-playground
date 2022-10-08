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

void Window::render(SDL_Texture* _toTexture_)
{
    SDL_RenderCopy(_renderer, _toTexture_, NULL, NULL);
}

SDL_Texture* Window::loadTexture(const char* _path_)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(_renderer, _path_);

    if (texture == NULL)
        std::cout << "IMG_LOAD ERROR: " << SDL_GetError() << std::endl;

    return texture;
}