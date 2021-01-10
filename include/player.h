#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "bullet.h"
#include "input.h"

typedef struct
{
    Character* Character_;
    int Lives;
    boolean IsAlive;
    boolean IsDead;
    GameObject* life1;
    GameObject* life2;
    GameObject* life3;
    InputSystem* Input;
} Player;


Player* NewPlayer(Point*, Size*, InputSystem*, int, float, char*);
void RenderPlayer(SDL_Renderer*, Player*, double);

boolean UpdatePlayer(SDL_Renderer*, SDL_Event*, Player*, double);
void DestroyPlayer(Player*);

#endif /*PLAYER_H*/