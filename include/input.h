#ifndef INPUT_H
#define INPUT_H

#include <common.h>
#include <list.h>
#include <character.h>
#include <bullet.h>

typedef struct
{
    boolean IsActive;
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
    SDL_Scancode shoot;
} InputSystem;

InputSystem* NewInputSystem(char*);
void DestroyInputSystem(InputSystem*);
void init_buttons(InputSystem*, char*);

void Movement(SDL_Event*, InputSystem*, Character*, double, List*);
boolean UpdateInputSystem(SDL_Event*, InputSystem*, Character*, double, List*);

void shoot (Character*, List*);

#endif // INPUT_H