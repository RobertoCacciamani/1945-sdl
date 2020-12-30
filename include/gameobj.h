#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <common.h>
#include <renderer.h>

typedef struct
{
    point position;
    size texture_size;
    char* texture_path;
    SDL_Rect* rect;
} GameObject;

GameObject* NewGameObject(point,size, char* );

void RenderGameObject(SDL_Renderer*, GameObject*);

#endif // GAMEOBJECT_H