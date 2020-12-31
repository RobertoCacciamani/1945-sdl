#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobj.h"

typedef struct{
    GameObject Go;
    int Hp;
    float Speed;
    char* Name;
} character;

void newCharacter(character* c, int hp, float speed, char* path, point p, size s);

#endif // CHARACTER_H
