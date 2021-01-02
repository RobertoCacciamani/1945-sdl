#include <input.h>

void init_buttons(InputSystem* inputsys, char* system_movement){
    if (!strcmp(system_movement, "wasd"))
    {
        printf("WASD buttons selected.\n");
        inputsys->up = SDL_SCANCODE_W;
        inputsys->left = SDL_SCANCODE_A;
        inputsys->down = SDL_SCANCODE_S;
        inputsys->right = SDL_SCANCODE_D;
    }
    else if (!strcmp(system_movement, "arrow"))
    {
        printf("ARROWS buttons selected.\n");
        inputsys->up = SDL_SCANCODE_UP;
        inputsys->left = SDL_SCANCODE_LEFT;
        inputsys->down = SDL_SCANCODE_DOWN;
        inputsys->right = SDL_SCANCODE_RIGHT;
    }
}

void InitInputSystem(InputSystem* input_, char* system_buttons){
    input_->IsActive = true;
    init_buttons(input_, system_buttons);
}

void Movement(SDL_Event* event, InputSystem* inputSys, Character* c, double* delta_time){
    if(inputSys->IsActive){
        if (event->type == SDL_KEYDOWN)
        {
            if(event->key.keysym.scancode == inputSys->up){  // up
                c->Go.position.y += -1 * c->Speed * (*delta_time);
                //printf("Movement called: up\n");
            }
            if(event->key.keysym.scancode == inputSys->left){  // left
                c->Go.position.x += -1 * c->Speed * (*delta_time);
                //printf("Movement called: left\n");
            }
            if(event->key.keysym.scancode == inputSys->down){  // down
                c->Go.position.y += 1 * c->Speed * (*delta_time);
                //printf("Movement called: down\n");
            }
            if(event->key.keysym.scancode == inputSys->right){  // right
                c->Go.position.x += 1 * c->Speed * (*delta_time);
                //printf("Movement called: right\n");
            }
        }
    }
}
