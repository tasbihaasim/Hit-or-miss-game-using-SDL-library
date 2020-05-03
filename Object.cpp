
#include "Object.hpp"
#include "TextureManager.hpp"


Object::Object(const char *path, SDL_Renderer *renderer)
{
    _renderer = renderer;
    cout << "reached";
    objtexture = TextureManager::Loadtex(path, renderer);
    dst_rect.h = 80;
    dst_rect.w = 100;
    dst_rect.x = xpos = 50;
    dst_rect.y = ypos = 50;
}

void Object::update()
{
    dst_rect.y = ypos;
    dst_rect.x = xpos;
}

void Object::update(player * p){
    
    dst_rect.y = ypos;
    dst_rect.x = xpos;
}

void Object::render()
{
    SDL_RenderCopy(_renderer, objtexture, nullptr, &dst_rect);
}

Object::~Object()
{
    SDL_DestroyTexture(objtexture); //memory deallocation
}

//string Object::type = "obj";