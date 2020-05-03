#include "player.hpp"
#include <string.h>
#include <SDL_image.h>
#include <SDL.h>
#include <cmath>
#include <iostream>

using namespace std;

void player::operator++()
{
    score++;
}
void player::inc()
{
    ++score;
}
int player::getscore()
{
    return round(score / 900);
}

player::player()
{
    score = 0;
}