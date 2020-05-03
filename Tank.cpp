#include "Tank.hpp"
int i = 5;
Object *get(list<Object *> _list, int _i)
{
    list<Object *>::iterator it = _list.begin();
    for (int i = 0; i < _i; i++)
    {
        ++it;
    }
    return *it;
}
string Tank::gettype(){
    return "Tank";
}
int Tank::what()
{
    return 1;
}
string Tank::type = "Tank";
Tank::Tank(const char *path, SDL_Renderer *renderer, int x, int y, list<Object *> &objs)
{ //int x, int y){
    list<Object *>::iterator it;
    speed = rand() % 5 + 2;
    _renderer = renderer;
    cout << "reached";
    objtexture = TextureManager::Loadtex(path, renderer);
    dst_rect.h = 40;
    dst_rect.w = 80;
    dst_rect.x = xpos = x;
    dst_rect.y = ypos = y;

    for (it = objs.begin(); it != objs.end(); it++)
    {

        if (((*it)->xpos >= 400) || ((*it)->ypos <= 0))
        {
            objs.remove(*it); //memory clean up after object moves outside the window
        }
    }
}

void Tank::update()
{
    dst_rect.y = ypos;
    dst_rect.x = xpos;
}

void Tank::clean(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer); //memory clean up
}
