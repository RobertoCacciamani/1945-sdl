#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

typedef struct
{
    Character* Character_;
    int Lives;
    boolean IsAlive;
    GameObject* life1;
    GameObject* life2;
    GameObject* life3;
} Player;


Player* NewPlayer(Point*, Size*, int, float, char*);
void RenderPlayer(SDL_Renderer*, Player*, double);

void UpdatePlayer(SDL_Renderer*, Player*, double);
void DestroyPlayer(Player*);

#endif /*PLAYER_H*/