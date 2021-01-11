#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <common.h>
#include <renderer.h>

typedef struct
{
    char* texture_path;
    Point* position;
    Size* texture_size;
    boolean IsActive;
    SDL_Rect* MyRect;
} GameObject;

enum IslandsType{Normal = 0, Vulcan, Sand};
typedef enum IslandsType_ IslandsType;

GameObject* NewGameObject(Point*, Size*, char* );

void RenderGameObject(SDL_Renderer*, GameObject*);
void GenericAddElemList(List*, int, char*, int);

GameObject* NewIsland(IslandsType);
void RenderGameObjectList(SDL_Renderer*, List*, boolean, float);
void RenderActiveGameObject(SDL_Renderer*, GameObject*, boolean);

void DestroyGameObject(GameObject*);

#endif // GAMEOBJECT_H