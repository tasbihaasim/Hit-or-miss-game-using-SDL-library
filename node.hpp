#pragma once

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "Object.hpp"

//Node used in the Linked List
struct node
{
    Object *data; //Stores the shape
    node *next;   //Pointer to the next node in the list
};