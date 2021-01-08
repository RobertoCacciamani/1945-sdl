#include <input.h>

void init_buttons(InputSystem* inputsys, char* system_movement){
    if (!strcmp(system_movement, "wasd"))
    {
        printf("WASD buttons selected.\n");
        inputsys->up = SDL_SCANCODE_W;
        inputsys->left = SDL_SCANCODE_A;
        inputsys->down = SDL_SCANCODE_S;
        inputsys->right = SDL_SCANCODE_D;
        inputsys->shoot = SDL_SCANCODE_SPACE;
    }
    else if (!strcmp(system_movement, "arrow"))
    {
        printf("ARROWS buttons selected.\n");
        inputsys->up = SDL_SCANCODE_UP;
        inputsys->left = SDL_SCANCODE_LEFT;
        inputsys->down = SDL_SCANCODE_DOWN;
        inputsys->right = SDL_SCANCODE_RIGHT;
        inputsys->shoot = SDL_SCANCODE_SPACE;
    }
}

InputSystem* NewInputSystem(char* system_buttons){
    InputSystem* input_ = (InputSystem*)calloc(1, sizeof(InputSystem));
    input_->IsActive = true;
    init_buttons(input_, system_buttons);
    return input_;
}

void DestroyInputSystem(InputSystem* input_){
    free(input_);
}

void Movement(SDL_Renderer* renderer, SDL_Event* event, InputSystem* inputSys, Character* c, Size* window, double* delta_time, List* bullets){
    if(inputSys->IsActive){
        if (event->type == SDL_KEYDOWN)
        {
            if(event->key.keysym.scancode == inputSys->up){  // up
                if (c->Go->position.y > 0)
                {
                    c->Go->position.y += -1 * c->Speed * (*delta_time);
                    //printf("Movement called: up\n");
                }
            }
            if(event->key.keysym.scancode == inputSys->left){  // left
                if (c->Go->position.x > 0)
                {
                    c->Go->position.x += -1 * c->Speed * (*delta_time);
                    //printf("Movement called: left\n");
                }
            }
            if(event->key.keysym.scancode == inputSys->down){  // down
                if (c->Go->position.y < (window->Height - 95) - c->Go->texture_size.Height)
                {
                    c->Go->position.y += 1 * c->Speed * (*delta_time);
                    //printf("Movement called: down\n");
                }
            }
            if(event->key.keysym.scancode == inputSys->right){  // right
                if (c->Go->position.x < window->Width - c->Go->texture_size.Width)
                {
                    c->Go->position.x += 1 * c->Speed * (*delta_time);
                    //printf("Movement called: right\n");
                }
            }
            if(event->key.keysym.scancode == inputSys->shoot){  // shoot
                shoot(renderer, c, window, delta_time, bullets);
            }
        }
    }
}

void shoot (SDL_Renderer* renderer, Character* c, Size* window, double* deltatime, List* bullets){
    if (c->Go->position.y > 0)
    {
        int count = 0;
        int index = 0;
        //int active = 0;
        Node* each = bullets->__head;
        while (each)
        {
            Node* next = each->next;
            if (((Bullet*)each->data)->Go->IsActive == false)
            {
                ((Bullet*)each->data)->Go->IsActive = true;
                ((Bullet*)each->data)->Go->position.x = c->Go->position.x + (c->Go->texture_size.Width * 0.5f) - (((Bullet*)each->data)->Go->texture_size.Width * 0.5f);
                ((Bullet*)each->data)->Go->position.y = c->Go->position.y + ((Bullet*)each->data)->Go->texture_size.Height;
                index = count;
                printf("count: %d\nactive: %d\n", index, (int)((Bullet*)each->data)->Go->IsActive);
                break;
            }
            count++;
            each = next;
        }
    }
}
