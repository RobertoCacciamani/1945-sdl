#include "player.h"

Player* NewPlayer(Point* p, Size* s, InputSystem* input, int hp, float speed, char* text_path){// int hp, float speed, char* path, Point* p, Size* s){
    Player* player = (Player*)calloc(1, sizeof(Player));
    player->Character_ = NewCharacter(hp, speed, text_path, p,s);
    player->Lives = 3;
    player->IsAlive = true;
    player->IsDead = false;
    player->life1 = NewGameObject(NewPoint(100,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    player->life2 = NewGameObject(NewPoint(55,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    player->life3 = NewGameObject(NewPoint(10,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    GenericAddElemList(player->Character_->bullets, 10, (char*)"bullet", playerBullet);
    player->Input = input;
    return player;
}

boolean UpdatePlayer(SDL_Renderer* renderer, SDL_Event* events, Player* player, double dt){
    UpdateBullets(renderer, player->Character_->bullets, dt);

    switch(player->Lives){
        case 3:
            RenderGameObject(renderer, player->life1);
            RenderGameObject(renderer, player->life2);
            RenderGameObject(renderer, player->life3);
            break;
        case 2:
            RenderGameObject(renderer, player->life1);
            RenderGameObject(renderer, player->life2);
            break;
        case 1:
            RenderGameObject(renderer, player->life1);
            break;
    }

    if(player->Character_->Hp > 0){
        //player->Character_->Hp -= 0.05f;
    }
    else if (player->Character_->Hp <= 0 && player->Lives > 0 && player->IsAlive)
    {
        printf("hai perso una vita! :(\n");
        player->Lives--;
        player->Character_->Go->IsActive = false;
        player->IsAlive = false;
        player->Input->IsActive = false;
    }

    if (player->IsAlive == false && player->Lives != 0)
    {
        if(RenderingThisAnimation(renderer, player->Character_->Animator_, "explosion", player->Character_->Go->position, dt)){
            player->Character_->Hp = 100;
            player->Character_->Go->IsActive = true;
            player->IsAlive = true;
            player->Input->IsActive = true;
        }
    }
    else if (player->IsAlive == false && player->Lives == 0 && !player->IsDead){
        if(RenderingThisAnimation(renderer, player->Character_->Animator_, "explosion", player->Character_->Go->position, dt)){
            player->Character_->Go->IsActive = false;
            player->IsDead = true;
            player->Input->IsActive = false;
        }
    }
    
    UpdateCharacter(renderer, player->Character_, dt);
    
    RenderingPath(renderer, (char*)"./assets/ui/hp.png", NewPoint(12, HEIGHT_WINDOW -40), NewSize(126 * player->Character_->Hp / 100, 13));

    return UpdateInputSystem(events, player->Input, player->Character_, dt, player->Character_->bullets);
}

void DestroyPlayer(Player* p){
    DestroyCharacter(p->Character_);
    DestroyGameObject(p->life1);
    DestroyGameObject(p->life2);
    DestroyGameObject(p->life3);
    DestroyInputSystem(p->Input);
    free(p);
}