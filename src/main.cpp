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

    Base      xBase = Base(-1, SIZE_X, 1) ;
    Base      yBase = Base(-1, SIZE_Y, 1) ;
    Basis2    basis = Basis2(xBase, yBase);
    WaveFunc2 psi   = WaveFunc2(basis)    ;

    Complex   probAmps[SIZE_X][SIZE_Y]    ;
    Vertex    vertices[SIZE_X][SIZE_Y]    ;

    psi.setValues(&probAmps[0][0]);
    
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            float x = xBase.x(i);
            float y = yBase.x(j);

            probAmps[i][j] = Complex(exp(10 * (- x * x - y * y))) * cis(100 * x + 150 * y);
            vertices[i][j] = Vertex(i, j, &psi, &window);
        }

    SDL_Event event;
    while (window.isRunning)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                window.cleanUp();

        window.clear();
        
        psi.evolve(4);
        for (int i = 0; i < SIZE_X; i++)
            for (int j = 0; j < SIZE_Y; j++)
                vertices[i][j].render();

        window.display();
    }

    SDL_Quit();
    return 0;
}