#pragma once
#include "game.hpp"

class TextureManager{
public:
    static SDL_Texture* Loadtex (const char* filepath, SDL_Renderer* ren);
    ~TextureManager();
};


