#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "input.h"
#include "ui.h"
#include "ttf.h"

typedef struct
{
    Character* Character_;
    int Lives;
    int score;
    boolean IsAlive;
    boolean IsDead;
    GameObject* life1;
    GameObject* life2;
    GameObject* life3;
    InputSystem* Input;
    Font* font;
} Player;


Player* NewPlayer(Point*, Size*, InputSystem*, int, float, char*);

boolean UpdatePlayer(SDL_Renderer*, SDL_Event*, Player*, double);
void DestroyPlayer(Player*);

#endif /*PLAYER_H*/