#include "Plane.hpp"

Plane::Plane(const char *path, SDL_Renderer *renderer)
{ //int x, int y){
    speed = rand() % 5 + 2;
    _renderer = renderer;
    //cout << "reached";
    objtexture = TextureManager::Loadtex(path, renderer);
    dst_rect.h = 80;
    dst_rect.w = 100;
    dst_rect.x = xpos = 0;
    dst_rect.y = ypos = rand() % 150 + 10;
}
string Plane::gettype()
{
    return "Plane";
}
void Plane::operator++()
{
    xpos += speed;
}

void Plane::clean(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer); //memory clean up
}

string Plane::type = "plane";

void Plane::update()
{
    dst_rect.y = ypos;
    dst_rect.x = xpos;
    xpos += speed;
}