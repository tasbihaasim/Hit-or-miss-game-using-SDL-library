#include "screen.hpp"
#include "TextureManager.hpp"

screen::screen(SDL_Renderer *gRenderer)
{
    objtexture = TextureManager::Loadtex("plane.png", gRenderer);
    bg.x = 0;
    bg.y = 0;
    bg.h = 600;
    bg.w = 600;
    start_button = TextureManager::Loadtex("click_to_start.png", gRenderer);
    sb.x = 100;
    sb.y = 450;
    sb.w = 240;
    sb.h = 80;
    title = TextureManager::Loadtex("title.png", gRenderer);
    t.x = 30;
    t.y = 380;
    t.h = 50;
    t.w = 320;
}
screen::~screen()
{
    SDL_DestroyTexture(title);
    SDL_DestroyTexture(start_button);
    SDL_DestroyTexture(objtexture);
}
void screen::show(SDL_Renderer *gRenderer)
{
    cout << "2" << endl;
    SDL_RenderCopy(gRenderer, objtexture, nullptr, &bg);
    SDL_RenderCopy(gRenderer, start_button, nullptr, &sb);
    SDL_RenderCopy(gRenderer, title, nullptr, &t);
    SDL_RenderPresent(gRenderer);
}