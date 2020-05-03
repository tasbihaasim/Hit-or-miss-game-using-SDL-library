#include "Bomb.hpp"

string Bomb::type = "bomb";
string Bomb::gettype()
{
    return "bomb";
}

Bomb::~Bomb()
{
    cout << "destructor called" << endl;
}
bool check_collision(SDL_Rect A, SDL_Rect B)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
    //If any of the sides from A are outside of B
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

Bomb::Bomb(const char *path, SDL_Renderer *renderer, int x, int y, list<Object *> &objs)
{
    obj = objs;
    speed = rand() % 5 + 2;
    _renderer = renderer;
    cout << "reached";
    objtexture = TextureManager::Loadtex(path, renderer);
    dst_rect.h = 30;
    dst_rect.w = 30;
    dst_rect.x = xpos = x;
    dst_rect.y = ypos = y;

    // for (it = objs.begin(); it != objs.end(); it++)
    // {
    //     pla = *it;

    //     if (((*it)->xpos >= 600) || ((*it)->ypos <= 0))
    //     {
    //         objs.remove(*it); //memory clean up after object moves outside the window
    //     }
    // }
}

bool c;
void Bomb::update(player *pl)
{
    list<Object *>::iterator it;

    dst_rect.y = ypos;
    dst_rect.x = xpos;
    //pl -> inc();

    ypos = ypos - 10;

    for (it = obj.begin(); it != obj.end(); it++)
    {

        // if (((*it)->xpos >= 600) || ((*it)->ypos <= 0) || ((*it)->xpos <= 0) || ((*it)->ypos >= 600))
        // {

        //     obj.remove(*it);
        //     delete *it;
        //     //memory clean up after object moves outside the window
        // }

        if (check_collision(*(*it)->getrect(), this->dst_rect))
            cout << "collided";
        ++(*pl);
        cout << " s " << pl->getscore() << "\n s \n";
    }

    // cout << (pla)->xpos << ";" << (pla)->ypos << endl;
    // cout << (this)->xpos << ";" << (this)->ypos << endl;

    // bool c = check_collision((pla)->dst_rect, this->dst_rect);
    // if (c == true)
    // {
    //     obj.remove(pla);
    //     cout << "collided" << endl;
    // }
}
void Bomb::clean(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer); //memory deallocation
}
