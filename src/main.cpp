#define SDL_MAIN_HANDLED

#include "../include/Dirac/dirac.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>

#include "../include/playgroundparams.h"
#include "../include/playgroundtest.h"
#include "../include/window.hpp"
#include "../include/vertex.hpp"

int main(int argc, char* args[])
{
    playground::testVideo();
    playground::testImage();

    Window window = Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    float values = 0.5;
    Vertex<float> vertices[SIZE_X][SIZE_Y];

    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
                vertices[i][j] = Vertex<float>(values, i, j, &window);

    SDL_Event event;
    while (window.isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) window.cleanUp();
        }
        
        for (int i = 0; i < SIZE_X; i++)
            for (int j = 0; j < SIZE_Y; j++)
                vertices[i][j].render();

        window.display();
    }

    SDL_Quit();
    return 0;
}