#include "game_over.hpp"
#include "TextureManager.hpp"

game_over::game_over(SDL_Renderer *gRenderer)
{
    objtexture = TextureManager::Loadtex("game_over.jpg", gRenderer);
    bg.x = 0;
    bg.y = 0;
    bg.h = 600;
    bg.w = 600;
  

}

void game_over::show(SDL_Renderer *gRenderer)
{
    cout << "2" << endl;
    SDL_RenderCopy(gRenderer, objtexture, nullptr, &bg);
 
    SDL_RenderPresent(gRenderer);
}