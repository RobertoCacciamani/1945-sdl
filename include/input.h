#ifndef INPUT_H
#define INPUT_H

#include <common.h>
#include <aiv-vector.h>
#include <character.h>

typedef struct
{
    boolean IsActive;
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
} InputSystem;

void InitInputSystem(InputSystem* input_, char* system_buttons);
void init_buttons(InputSystem* inputsys, char* system_movement);

void Movement(SDL_Event* event, InputSystem* inputSys, Character* c, double* delta_time);

#endif // INPUT_H