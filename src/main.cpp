#define SDL_MAIN_HANDLED

#include "../include/Dirac/dirac.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>
#include <cmath>

#include "../include/playgroundparams.h"
#include "../include/playgroundtest.h"
#include "../include/window.hpp"
#include "../include/vertex.hpp"

int main(int argc, char* args[])
{
    playground::testVideo();
    playground::testImage();

    Window window = Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    Base      x     = Base(-1, SIZE_X, 1); 
    Base      y     = Base(-1, SIZE_Y, 1);
    Basis2    basis = Basis2(x, y)       ;
    WaveFunc2 psi   = WaveFunc2(basis)   ;

    Complex         probAmps[SIZE_X][SIZE_Y];
    Vertex<Complex> vertices[SIZE_X][SIZE_Y];

    psi.setValues(&probAmps[0][0]);
    
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            probAmps[i][j] = Complex(cos(i), sin(j));
            vertices[i][j] = Vertex<Complex>(&probAmps[i][j], i, j, &window);
        }

    SDL_Event event;
    while (window.isRunning)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                window.cleanUp();

        window.clear();
        
        psi.evolve(1);
        for (int i = 0; i < SIZE_X; i++)
            for (int j = 0; j < SIZE_Y; j++)
                    vertices[i][j].render();

        window.display();
    }

    SDL_Quit();
    return 0;
}