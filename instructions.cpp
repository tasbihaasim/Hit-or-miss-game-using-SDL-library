
using namespace std;
#include "instructions.hpp"
#include "TextureManager.hpp"

instructions::instructions(SDL_Renderer *gRenderer) : screen(gRenderer)
{
    objtexture = TextureManager::Loadtex("instruct.png", gRenderer);
    bg.x = 0;
    bg.y = 0;
    bg.h = 600;
    bg.w = 600;
   
}

void instructions::show(SDL_Renderer *gRenderer)
{
    cout << "2" << endl;
    SDL_RenderCopy(gRenderer, objtexture, nullptr, &bg);

    SDL_RenderPresent(gRenderer);
}