#pragma once
#include "Object.hpp"
#include "Object.hpp"
#include "player.hpp"
#include <iomanip>
#include <list>
#include "TextureManager.hpp"
class Bomb : public Object
{
private:
    int speed;
    Object *pla;
    list<Object *> obj;

public:
    Bomb(const char *path, SDL_Renderer *renderer, int x, int y, list<Object *> &objs);
    void clean(SDL_Renderer *gRenderer);

    //void update() override;
    void update(player *) override;
    static string type;
    string gettype() override;
    ~Bomb();
    //void render() override;
};