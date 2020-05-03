//#include "Point.hpp"
#pragma once
#include "SDL.h"

//#include "Color.hpp"

class game_over
{
public:
    SDL_Window *gwindow;

    SDL_Texture *objtexture;
    SDL_Texture *start_button;
    SDL_Texture *title;
    SDL_Rect t;
    SDL_Rect sb;
    SDL_Rect bg;
    //virtual void quit();

    game_over(SDL_Renderer *);

    bool initialize();

    void show(SDL_Renderer *);
};