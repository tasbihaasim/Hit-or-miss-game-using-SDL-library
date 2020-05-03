#pragma once
#include "game.hpp"
#include "player.hpp"

using namespace std;

class Object
{
public:
    SDL_Rect dst_rect;
    SDL_Rect src_rect;
    SDL_Renderer *_renderer;
    SDL_Texture *objtexture;

public:
    int xpos, ypos;
    virtual string gettype()=0;

public:
    Object(const char *path, SDL_Renderer *renderer);
    Object(){};
    SDL_Texture *loadTexture(const char *path, SDL_Renderer *gRenderer);

    //Object(int, int, int, int, int, int, int, int, string, SDL_Renderer *);
    ~Object();
    virtual SDL_Rect *getrect()
    {
        return &dst_rect;
    }
    virtual void update();
    virtual void update(player *);
    virtual void render();
};
