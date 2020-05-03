#pragma once
#include <string.h>
#include <SDL_image.h>
#include <SDL.h>
#include <iostream>

class player
{
private:
    int score;

public:
    static player *instance();
    player();
    int getscore();
    void operator++();
    void inc();
};