#pragma once
#include "Object.hpp"
#include "TextureManager.hpp"

class Plane : public Object
{
private:
    int speed;

public:
    Plane(const char *path, SDL_Renderer *renderer); //int x, int y);

    void update() override;
    void clean(SDL_Renderer *); //memory clean up
    static string type;
    string gettype() override;
    void operator++();
    //void render() override;
};
