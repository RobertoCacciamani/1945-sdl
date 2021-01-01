#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobj.h"

typedef struct
{
    GameObject Go;
    int Hp;
    float Speed;
    char* Name;
} Character;

void newCharacter(Character* c, int hp, float speed, char* path, point p, size s);
void RenderCharacter(SDL_Renderer* render, Character* c);

#endif // CHARACTER_H
