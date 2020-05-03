#include "TextureManager.hpp"

#include "TextureManager.hpp"


SDL_Texture* TextureManager::Loadtex(const char* filepath, SDL_Renderer* ren){
    SDL_Surface *temp = IMG_Load(filepath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,temp);
    SDL_FreeSurface(temp);
    return tex;
}
TextureManager::~TextureManager(){
};

