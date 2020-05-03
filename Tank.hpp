#pragma once
#include "Object.hpp"
#include "Object.hpp"
#include <iomanip>
#include <list>
#include "TextureManager.hpp"

class Tank : public Object
{
private:
    int speed;

public:
    Tank(const char *path, SDL_Renderer *renderer, int x, int y, list<Object *> &objs);
    void clean(SDL_Renderer *gRenderer);
    int what();
    static string type;
    string gettype() override;
    void update() override;

    void moveright()
    {
        xpos += 4;
    }

    void moveleft()
    {
        xpos -= 4;
    }

    float getx()
    {
        return xpos;
    }

    float gety()
    {
        return ypos;
    }
    //void render() override;
};