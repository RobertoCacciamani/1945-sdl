#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobj.h"


typedef struct
{
    double Hp;
    float Speed;
    GameObject* Go;
    Animator* Animator_;
} Character;

Character* NewCharacter(int, float, char*, Point*, Size*);
void UpdateCharacter(SDL_Renderer*, Character*, double);

void AddAnimation(Character*, char*, char*, SDL_Rect*, int, double);

void DestroyCharacter(Character*);

#endif // CHARACTER_H
