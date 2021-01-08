#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <common.h>
#include <renderer.h>

typedef struct
{
    char* texture_path;
    Point position;
    Size texture_size;
    boolean IsActive;
} GameObject;

GameObject* NewGameObject(Point, Size, char* );

void RenderGameObject(SDL_Renderer*, GameObject*);

void GenericAddElemList(List*, int, char*, int);

void DestroyGameObject(GameObject*);
//void elemInList(List* l, int n);//, void* (struct_ptr), void* (function_ptr)());//, void (action)(), void* elem);

#endif // GAMEOBJECT_H