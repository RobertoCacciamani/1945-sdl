#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobj.h"

typedef struct
{
    int Hp;
    float Speed;
    GameObject* Go;
} Character;

Character* NewCharacter(int hp, float speed, char* path, Point p, Size s);
void RenderCharacter(SDL_Renderer* render, Character* c);

void DestroyCharacter(Character* c);

#endif // CHARACTER_H
