
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>

#include <iostream>
#include "game.hpp"
#include "screen.hpp"
#include "instructions.hpp"
#include "game_over.hpp"
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

bool init()
{
    //Initialization mouseClicked
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_JPG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success mouseClicked
    bool success = true;

    //Nothing to load
    return success;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char *args[])
{

    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia()) //Load media
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            screen *sc = new screen(gRenderer);
            game Game;
            Uint32 start;
            // int f = 0;
            // int ti = 0;

            while (!quit)
            {
                // while (ti < 30)
                // {
                //     f++;
                //     if (f % 20 == 0)
                //     {
                //         ti++;
                //     }
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                sc->show(gRenderer);

                if (e.key.keysym.sym)
                {
                    close();
                    Game.initialize();

                    while (Game.Isrunning())
                    {
                        start = SDL_GetTicks();

                        Game.update();
                        Game.handleevents();
                        Game.render();

                        if ((1000 / 60) > SDL_GetTicks() - start)
                        {
                            SDL_Delay(1000 / 60 - (SDL_GetTicks() - start));
                        }
                        if (e.type == SDL_QUIT)
                        {
                            break;
                            quit = true;
                        }
                    }

                    Game.clean();

                    break;
                }

                //complete clean up, windows and Renderer destroyed
            }
            //}
        }
    }
    close();
    return 0;
}
