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
    const uint32_t WINDOW_WIDTH  =  720u             ;
    const uint32_t WINDOW_HEIGHT =  720u             ;
    const uint32_t SIZE_X        =  36u              ;
    const uint32_t SIZE_Y        =  36u              ;
    const float    START_X       = -30.0f            ;
    const float    END_X         =  30.0f            ;
    const float    START_Y       = -30.0f            ;
    const float    END_Y         =  30.0f            ;
    const float    INIT_X        =  0.0f             ;
    const float    INIT_Y        =  0.0f             ;
    const float    DIV           =  0.1f             ;
    const float    MOMENTUM_X    =  1000000000000.0f ;
    const float    MOMENTUM_Y    =  0.0f             ;
    const float    DT            =  0.2f             ;

    Base       xBase = Base(START_X, SIZE_X, END_X);
    Base       yBase = Base(START_Y, SIZE_Y, END_Y);
    Basis2*    basis = new Basis2(xBase, yBase)    ;
    WaveFunc2* psi   = new WaveFunc2(basis)        ;

    Complex        probAmps[SIZE_X][SIZE_Y];
    griddy::Vertex vertices[SIZE_X][SIZE_Y];
    
    griddy::Window window = griddy::Window(
        WINDOW_TITLE ,
        WINDOW_WIDTH ,
        WINDOW_HEIGHT
    );

    griddy::Grid grid = griddy::Grid(&window);

    SDL_Rect rectGrid = SDL_Rect();
    rectGrid.x = 0            ;
    rectGrid.y = 0            ;
    rectGrid.w = WINDOW_WIDTH ;
    rectGrid.h = WINDOW_HEIGHT;

    grid.setVertices(&vertices[0][0]);
    grid.setPosition(rectGrid);
    grid.setSize(SIZE_X, SIZE_Y);

    psi->setValues(&probAmps[0][0]);
    psi->setNorm(255.0f);
    psi->setMass(1.0f);

    
    for (int i = 0; i < SIZE_X; i++)
        for (int j = 0; j < SIZE_Y; j++)
        {
            float x = xBase.x(i) - INIT_X;
            float y = yBase.x(j) - INIT_Y;

            probAmps[i][j] = Complex(exp((-x*x-y*y) / DIV)) * cis(MOMENTUM_X * x + MOMENTUM_Y * y);
            vertices[i][j] = griddy::Vertex(i, j);
        }

    SDL_Event event;
    while (window.isRunning)
    {
        while ( SDL_PollEvent(&event) )
            if (event.type == SDL_QUIT)
                window.destroy();

        window.clear();

        psi->evolve(DT);
        // THIS SECTION IS NOT OPTIMAL
        for (int i = 0; i < SIZE_X; i++)
            for (int j = 0; j < SIZE_Y; j++)
            {
                float thisProb = psi->prob(i, j);
                griddy::color thisColor = griddy::Color(0x00, thisProb, 0x00);
                vertices[i][j].setColor(thisColor);
            }
        // END OF SECTION
        grid.render();

        window.display();
    }

    SDL_Quit();                                                         // goodbye
    return 0;
}