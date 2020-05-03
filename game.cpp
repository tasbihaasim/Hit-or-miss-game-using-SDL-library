#include <string.h>
#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <list>

#include "game.hpp"
//#include "Object.hpp"
#include "Plane.hpp"
#include "bomb.hpp"
#include "Tank.hpp"
#include "player.hpp"

using namespace std;
player *p = new player();
//player * p = &plr;
void game::bg()
{
    SDL_Texture *obje = TextureManager::Loadtex("plane.png", renderer);
    SDL_Rect d;
    d.x = 0;
    d.y = 0;
    d.h = 800;
    d.w = 800;

    SDL_RenderCopy(renderer, obje, nullptr, &d);
    SDL_RenderPresent(renderer);
}
game::game()
{
}

Object *o;
list<Object *> planes;
list<Object *> projectiles;
list<Object *>::iterator it;
Tank *t;

//

Uint32 s = 0;
Uint32 q;
void game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //delete t;
    for (it = planes.begin(); it != planes.end(); it++)
    {
        delete *it;
    }
}
bool game::initialize()
{
    //Initialization mouseClicked
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
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
        window = SDL_CreateWindow("HIT OR MISS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (renderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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
    isrunning = true;
    t = new Tank("tank_s.png", renderer, x_cor, 530, planes);
    return success;
}

int x_c = 10;
void game::handleevents()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch (e.type)
    {
    case SDL_QUIT:
        isrunning = false;
        break;
    case SDL_KEYDOWN:
        if (e.key.keysym.sym == SDLK_RIGHT)
        {
            x_cor = x_cor + 10;
            t->moveright();
        }
        else if (e.key.keysym.sym == SDLK_LEFT)
        {

            x_cor = x_cor - 10;
            t->moveleft();
        }
        if (e.key.keysym.sym == SDLK_SPACE)
        {
            planes.push_back(new Bomb("sprite.png", renderer, t->getx() + 10, 420, planes));
        }
    default:
        break;
    }
}

void game::update()
{
    if (s < SDL_GetTicks())
    {
        planes.push_back(new Plane("jahaz.png", renderer));
        s = SDL_GetTicks() + 500;
        //maka bomb object here where objs remain the same but new bomb
    }

    t->update();

    for (it = planes.begin(); it != planes.end(); it++)
    {
        if ((*it)->gettype() == "bomb")
        {
            (*it)->update(p);
        }
        else
        {
            (*it)->update();
        }

        // if (((*it)->xpos >= 600) || ((*it)->ypos >= 600))
        // {
        //     objs.remove(*it);
        // }
    }
}

bool game::Isrunning()
{
    return isrunning;
}

void game::render()
{
    SDL_RenderClear(renderer);
    //code here

    t->render();
    for (it = planes.begin(); it != planes.end(); it++)
    {
        (*it)->render();
    }

    SDL_RenderPresent(renderer);
}
