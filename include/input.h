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

InputSystem* NewInputSystem(char* system_buttons);
void DestroyInputSystem(InputSystem* input_);
void init_buttons(InputSystem* inputsys, char* system_movement);

void Movement(SDL_Event* event, InputSystem* inputSys, Character* c, double* delta_time, List* bullets);

void shoot (Character* c, List* bullets);

#endif // INPUT_H