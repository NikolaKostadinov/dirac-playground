#define SDL_MAIN_HANDLED                                                // windows stuff

#include "../include/Dirac/dirac.h"
#include "../include/Griddy/griddy.h"
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include <iostream>
#include <cmath>

int main(int argc, char* args[])
{
    const char*    WINDOW_TITLE  = "Dirac Playground";
    const uint32_t WINDOW_WIDTH  = 720u              ;
    const uint32_t WINDOW_HEIGHT = 720u              ;
    const uint32_t SIZE_X        = 10u               ;
    const uint32_t SIZE_Y        = 10u               ;
    const float    INIT_X        = 0.0f              ;
    const float    INIT_Y        = 0.0f              ;
    const float    DIV           = 0.1f              ;
    const float    MOMENTUM_X    = 1.0f              ;
    const float    MOMENTUM_Y    = 2.0f              ;
    const float    DT            = 8.0f              ;

    Base       xBase =     Base( -1, SIZE_X, 1);
    Base       yBase =     Base( -1, SIZE_Y, 1);
    Basis2*    basis = new Basis2(xBase, yBase);
    WaveFunc2* psi   = new WaveFunc2(basis)    ;

    Complex        probAmps[SIZE_X][SIZE_Y];
    griddy::Vertex vertices[SIZE_X][SIZE_Y];
    
    griddy::Window window = griddy::Window(
        WINDOW_TITLE ,
        WINDOW_WIDTH ,
        WINDOW_HEIGHT
    );

    griddy::Grid grid = griddy::Grid(&window);

    
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            float x = xBase.x(i) - INIT_X;
            float y = yBase.x(j) - INIT_Y;

            vertices[i][j] = griddy::Vertex(i, j);
            probAmps[i][j] = Complex(exp((-x*x-y*y) / DIV)) * cis(MOMENTUM_X * x + MOMENTUM_Y * y);
        }

    psi->setValues(&probAmps[0][0]);

    SDL_Event event;
    while (window.isRunning)
    {
        while ( SDL_PollEvent(&event) )
            if (event.type == SDL_QUIT)
                window.destroy();

        window.clear();

        psi->evolve(DT);
        grid.render(  );

        window.display();
    }

    SDL_Quit();                                                         // goodbye
    return 0;
}