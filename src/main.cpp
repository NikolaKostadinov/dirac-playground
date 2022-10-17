#define SDL_MAIN_HANDLED                                                // windows stuff

#include "../include/Dirac/dirac.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>
#include <cmath>

#include "../include/playgroundparams.h"
#include "../include/playgroundtest.h"
#include "../include/window.hpp"
#include "../include/vertex.hpp"
#include "../include/dirac_data.hpp"
#include "../include/dirac_panel.hpp"

int main(int argc, char* args[])
{
    playground::testVideo();
    playground::testImage();

    Base      xBase = Base(-1, SIZE_X, 1) ;
    Base      yBase = Base(-1, SIZE_Y, 1) ;
    Basis2    basis = Basis2(xBase, yBase);
    WaveFunc2 psi   = WaveFunc2(basis)    ;

    Complex   probAmps[SIZE_X][SIZE_Y]    ;
    Vertex    vertices[SIZE_X][SIZE_Y]    ;

    psi.setValues(&probAmps[0][0]);
    psi.normalize(               );                                     // set and norm

    Window     window = Window(
        WINDOW_TITLE ,
        WINDOW_WIDTH ,
        WINDOW_HEIGHT
    )                                                              ;
    DiracData  data   = DiracData (&psi)                           ;
    DiracPanel dirac  = DiracPanel(&vertices[0][0], &window, &data);
                                                                        // simulation parameters:
    float initX = 0.0              ;                                    // * initial x postition
    float initY = 0.0              ;                                    // * initial x postition
    float div   = 0.1              ;                                    // * diviation of probability
    float xMntm = 1.0              ;                                    // * x momentum
    float yMntm = 2.0              ;                                    // * y momentum
    float dt    = 8.0              ;                                    // * time steps
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {

            float x = xBase.x(i) - initX;
            float y = yBase.x(j) - initY;

            probAmps[i][j] = Complex(exp((-x*x-y*y) / div)) * cis(xMntm * x + yMntm * y);
            vertices[i][j] = Vertex (i, j)                                              ;
        }

    SDL_Event event;
    while (window.isRunning)
    {
        while ( SDL_PollEvent(&event) )
            if (event.type == SDL_QUIT)
                window.cleanUp();

        window.clear()  ;
          
        dirac.evolve(dt);                                               // solving the cat equation
        dirac.render(  );                                               // let me see the wave-particle

        window.display();
    }

    SDL_Quit();                                                         // goodbye
    return 0;
}