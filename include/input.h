#ifndef INPUT_H
#define INPUT_H

#include <common.h>
#include <aiv-vector.h>
#include <character.h>

typedef struct
{
    boolean IsActive;

    avector* buttons;
} InputSystem;

typedef struct
{
    SDL_KeyCode button;
} key;

void InitInputSystem(InputSystem input_, char* system_buttons);
void init_buttons(avector* buttons, char* system_movement);
void set_button(key* k, SDL_KeyCode a);

void HorizontalMovement(SDL_Event* event, boolean* done, Character* c, float* delta_time);
void VerticalMovement(SDL_Event* event, boolean* done, Character* c, float* delta_time);
void Movement(SDL_Event* event, boolean* done, Character* c, float* delta_time);

#endif // INPUT_H