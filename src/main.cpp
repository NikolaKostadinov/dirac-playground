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
#include "../include/dirac_panel.hpp"

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
    psi.normalize();

    DiracPanel dirac = DiracPanel(&vertices[0][0], &psi, &window);

    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            float x = xBase.x(i);
            float y = yBase.x(j);

            probAmps[i][j] = Complex(sqrt(x*x + y*y));
            vertices[i][j] = Vertex (i, j, &dirac);
        }

    SDL_Event event;
    while (window.isRunning)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                window.cleanUp();

        window.clear()  ;
          
        psi.evolve(4)   ;
        dirac.render()  ;

        window.display();
    }

    SDL_Quit();
    return 0;
}