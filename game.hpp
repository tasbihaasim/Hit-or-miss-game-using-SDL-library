#pragma once
#include <string.h>
#include <SDL_image.h>
#include <SDL.h>
//#include <SDL_ttf.h>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class game
{
public:
    bool isrunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    int x_cor, y_cor;
    void bg();
    game();
    //void //operator ++();
    bool initialize();
    void update();
    void render();
    void clean(); //memory clean up
    void handleevents();
    bool Isrunning();
};
