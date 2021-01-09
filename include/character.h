#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobj.h"


typedef struct
{
    int Hp;
    float Speed;
    GameObject* Go;
    Animator* Animator_;
} Character;

Character* NewCharacter(int, float, char*, Point*, Size*);
void RenderCharacter(SDL_Renderer*, Character*);

void AddAnimation(Character*, char*, char*, SDL_Rect*, int);

void DestroyCharacter(Character*);

#endif // CHARACTER_H
