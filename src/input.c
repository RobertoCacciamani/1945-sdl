#include <input.h>

void set_button(key* k, SDL_KeyCode a){
    k->button = a;
}

void init_buttons(avector* buttons, char* system_movement){
    key up;
    key left;
    key down;
    key right;
    switch(*system_movement){
        case 'wasd':
            set_button(&up, SDLK_w);
            set_button(&left, SDLK_a);
            set_button(&down, SDLK_s);
            set_button(&right, SDLK_d);
            break;
        case 'bolt':
            set_button(&up, SDLK_UP);
            set_button(&left, SDLK_LEFT);
            set_button(&down, SDLK_DOWN);
            set_button(&right, SDLK_RIGHT);
            break;
        default:
            set_button(&up, SDLK_w);
            set_button(&left, SDLK_a);
            set_button(&down, SDLK_s);
            set_button(&right, SDLK_d);
            break;
            
    }
    aiv_vector_add(buttons, &up);
    aiv_vector_add(buttons, &left);
    aiv_vector_add(buttons, &down);
    aiv_vector_add(buttons, &right);
}

void InitInputSystem(InputSystem input_, char* system_buttons){
    input_.buttons = aiv_vector_new_with_cap(4);
    init_buttons(input_.buttons, system_buttons);
    // if(((key)(aiv_vector_at(input_.buttons, 0))).button == SDLK_w){
    //     //return 1;
    // }
}

void HorizontalMovement(SDL_Event* event, boolean* done, Character* c, float* delta_time){
    //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: %s\n", c->Name);
    switch(event->type){
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_RIGHT) {
                c->Go.position.x += 1 * c->Speed;// * (*delta_time);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down right");
            } else if (event->key.keysym.sym == SDLK_LEFT) {
                c->Go.position.x += -1 * c->Speed;// * (*delta_time);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down left");
            }
            break;
        default:
            break;
    }
}


void VerticalMovement(SDL_Event* event, boolean* done, Character* c, float* delta_time){
        switch(event->type){
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_UP) {
                c->Go.position.y += -1 * c->Speed;// * (*delta_time);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down right");
            } else if (event->key.keysym.sym == SDLK_DOWN) {
                c->Go.position.y += 1 * c->Speed;// * (*delta_time);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down left");
            }
            break;
        default:
            break;
    }
}

void Movement(SDL_Event* event, boolean* done, Character* c, float* delta_time){
    float moltiplicatore_delta = 100;
    switch(event->type){
        case SDL_KEYDOWN:
            if (event->key.keysym.sym == SDLK_RIGHT) {
                c->Go.position.x += 1 * c->Speed* (*delta_time * moltiplicatore_delta);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down right");
            }
            if (event->key.keysym.sym == SDLK_LEFT) {
                c->Go.position.x += -1 * c->Speed * (*delta_time * moltiplicatore_delta);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down left");
            }
            if (event->key.keysym.sym == SDLK_UP) {
                c->Go.position.y += -1 * c->Speed * (*delta_time * moltiplicatore_delta);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down right");
            }
            if (event->key.keysym.sym == SDLK_DOWN) {
                c->Go.position.y += 1 * c->Speed * (*delta_time * moltiplicatore_delta);
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "HorizontalMovement called: down left");
            }
            break;
        default:
            break;
    }
}

// switch (event.type) {
    // case SDL_QUIT:
    //     done = 1;
    //     break;
    // case SDL_KEYDOWN:
    //     if (event.key.keysym.sym == SDLK_RIGHT) {
    //         x_direction = 1;
    //     } else if (event.key.keysym.sym == SDLK_LEFT) {
    //         x_direction = -1;
    //     }
    //     break;
    // case SDL_KEYUP: 
    //     if (event.key.keysym.sym == SDLK_RIGHT) {
    //         x_direction = 0;
    //     } else if (event.key.keysym.sym == SDLK_LEFT) {
    //         x_direction = 0;
    //     }
    //     break;
    // default:
    //     break;
    // }
