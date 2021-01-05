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

void InitInputSystem(InputSystem* input_, char* system_buttons);
void init_buttons(InputSystem* inputsys, char* system_movement);

void Movement(SDL_Renderer* renderer, SDL_Event* event, InputSystem* inputSys, Character* c,
                 size* window, double* delta_time, List* bullets);

void shoot (SDL_Renderer* renderer, Character* c, size* window, double* deltatime, List* bullets);

#endif // INPUT_H