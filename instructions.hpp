
#include "node.hpp"
#include "screen.hpp"

class instructions : public screen
{
public:
    SDL_Window *gwindow;

    SDL_Texture *objtexture;
    SDL_Rect bg;
    //virtual void quit();
    instructions();
    instructions(SDL_Renderer *);

    bool initialize();

    void show(SDL_Renderer *);
};