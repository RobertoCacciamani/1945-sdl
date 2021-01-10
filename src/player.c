#include "player.h"

Player* NewPlayer(Point* p, Size* s, int hp, float speed, char* text_path){// int hp, float speed, char* path, Point* p, Size* s){
    Player* player = (Player*)calloc(1, sizeof(Player));
    player->Character_ = NewCharacter(hp, speed, text_path, p,s);
    player->Lives = 3;
    player->IsAlive = true;
    player->life1 = NewGameObject(NewPoint(100,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    player->life2 = NewGameObject(NewPoint(55,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    player->life3 = NewGameObject(NewPoint(10,HEIGHT_WINDOW-90), NewSize(40, 40), (char*)"./assets/ui/life.png");
    return player;
}

void UpdatePlayer(SDL_Renderer* renderer, Player* player, double dt){
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
        player->Character_->Hp -= 0.05f;
    }
    else if (player->Character_->Hp <= 0 && player->Lives != 0)
    {
        printf("hai perso una vita! :(\n");
        player->Character_->Hp = 100;
        player->Lives--; 
        RenderingThisAnimation(renderer, player->Character_->Animator_, "explosion", player->Character_->Go->position, dt);
    }
    else if (player->Lives == 0 && player->Character_->Hp <= 0){
        printf("Game Over!\n");
    }

    //printf("update_player -> dt: %f\n", dt);
    UpdateCharacter(renderer, player->Character_, dt);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    // SDL_RenderDrawLine(renderer,10,10,20,20);

    SDL_RenderDrawRect(renderer, NewRect(NewPoint(12, HEIGHT_WINDOW -38), NewSize(126 * player->Character_->Hp / 100, 9)));

    // if(player->Character_->Hp >= 0){
    //     SDL_RenderDrawRect(renderer, NewRect(NewPoint(10, HEIGHT_WINDOW -10), NewSize(player->Character_->Hp, 3)));
    // }
}

void DestroyPlayer(Player* p){
    DestroyCharacter(p->Character_);
    DestroyGameObject(p->life1);
    DestroyGameObject(p->life2);
    DestroyGameObject(p->life3);
    free(p);
}

// void PlayerDied(Player* player, double deltaTime, double delay){
    
//     delay += deltaTime;
//     if(player->Character_->Hp <= 0){
//         player->IsAlive = false;
//         if(delay >= 3){
//             printf("morto");
//             player->lives--;
//             printf("%d ", player->lives);
//             player->isAlive = true;
//             deltaTime = 0;
//         }

//     }
    
// }
