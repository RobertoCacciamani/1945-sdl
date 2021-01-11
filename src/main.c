//Per dire a SDL che si usera' il proprio main applicativo.
//Altrimenti SDL cerca di caricare il main da SDL2Main.lib
//NOTA: Si può passare anche come argomento di compilazione con -D
#define SDL_MAIN_HANDLED
#include <common.h>
#include <renderer.h>
#include <gameobj.h>
#include <input.h>
#include <bullet.h>
#include "player.h"
#include "enemy.h"
#include "ui.h"
#include "physics.h"


int main() {
    SDL_Init(SDL_INIT_VIDEO);

    Size* win = NewSize(WIDTH_WINDOW, HEIGHT_WINDOW);

    SDL_Window* window = SDL_CreateWindow(
        "1945",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        win->Width,
        win->Height,
        0
    );

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not create renderer: %s\n", SDL_GetError());
        return 2;
    }

    Uint64 curr_count = SDL_GetPerformanceCounter();
    Uint64 last_count = curr_count;
    double delta_time = 0.f;
    
    char title[100];
    float update_time = 0.f;
    
    Player* player = NewPlayer(NewPoint(290,180), NewSize(65,65), NewInputSystem((char*)"wasd"),100, 1000, (char*)"./assets/player/myplane_strip3.png");
    AddAnimation(player->Character_, (char*)"main", (char*)"./assets/player/myplane_strip3.png", NewRect(NewPoint(player->Character_->Go->position->x,0), player->Character_->Go->texture_size), 3, 0.03f);
    AddAnimation(player->Character_, (char*)"explosion", (char*)"./assets/player/explosion2_strip7.png", NewRect(NewPoint(player->Character_->Go->position->x,0), player->Character_->Go->texture_size), 7, 0.1f);
    
    EnemyManager* enemymgr = NewEnemyManager();
    AddEnemyManagerList(enemymgr, NewSize(32,32), (char*)"./assets/enemy/enemy1_strip3.png");
    
    PhysicsManager* physicsManager = NewPhysicsManager(player, enemymgr);

    Interface* ui = NewInterface();
    AddUiList(ui, NewPoint(0,HEIGHT_WINDOW-99), NewSize(WIDTH_WINDOW, 100), (char*)"./assets/ui/bottom.png");

    List* Islands = NewList();
    GenericAddElemList(Islands, 2, (char*)"island", Normal);
    GenericAddElemList(Islands, 2, (char*)"island", Vulcan);
    GenericAddElemList(Islands, 2, (char*)"island", Sand);

    List* Water = NewList();
    GenericAddElemList(Water, 1, (char*)"background", 0);

    boolean done = false;

    SDL_Event* event = (SDL_Event*)calloc(1, sizeof(SDL_Event));
    while (!done) {
        SDL_RenderClear(renderer);

        // DELTATIME
        last_count = curr_count;
        curr_count = SDL_GetPerformanceCounter();
        delta_time = (float)(curr_count - last_count) / (float)SDL_GetPerformanceFrequency();
        int fps = (int)(1.f / delta_time);

        update_time += delta_time;
        if (update_time >= 1.f) {
            update_time -= 1.f;
            sprintf_s(title, sizeof(title), "Delta Time: %.6f - Fps: %d", delta_time, fps);
            SDL_SetWindowTitle(window, title);
        }
        
        // BACKGROUND
        RenderGameObjectList(renderer, Water, true, delta_time);
        RenderGameObjectList(renderer, Islands, false, delta_time);

        CheckCollision(physicsManager);

        // TEST
        //RenderingThisAnimation(renderer, player->Character_->Animator_, (char*)"explosion", player->Character_->Go->position, delta_time);
        UpdateEnemyManager(renderer, enemymgr, delta_time);
        
        // UI BASE
        UpdateInterface(renderer, ui, delta_time);
        //RenderGameObject(renderer, ui_bottom);

        // PLAYER (INPUT, BULLETS, LIFE MANAGER)
        done = UpdatePlayer(renderer, event, player, delta_time);

        // BLIT
        SDL_RenderPresent(renderer);
    }

    //CLEAN UP
    CloseWindow(renderer, window);

    // DestroyGameObject(life1);
    // DestroyGameObject(life2);
    // DestroyGameObject(life3);
    //DestroyGameObject(ui_bottom);
    //DestroyGameObject(background);

    //DestroyList(bullets);
    DestroyPlayer(player);
    DestroyInterface(ui);
    //DestroyCharacter(player);
    //DestroyInputSystem(inputSystem);

    return 0;
}