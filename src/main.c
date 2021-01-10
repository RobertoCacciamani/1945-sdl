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

    // if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    //     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "could not initialize sdl_image: %s\n", IMG_GetError());
    //     return false;
    // }

    Uint64 curr_count = SDL_GetPerformanceCounter();
    Uint64 last_count = curr_count;
    double delta_time = 0.f;
    
    char title[100];
    float update_time = 0.f;
    //float time_counter = 0.f;
    
    // GameObject player;
    // NewGameObject(&player, NewPoint(10,10), NewSize(50,50), "./assets/ui/life.png");

    // Character* player = NewCharacter(100, 15000, (char*)"./assets/player/myplane_strip3.png", NewPoint(290,180), NewSize(65,65));
    // AddAnimation(player, (char*)"main", (char*)"./assets/player/myplane_strip3.png", NewRect(NewPoint(player->Go->position->x,0), player->Go->texture_size), 3, 0.03f);
    // AddAnimation(player, (char*)"explosion", (char*)"./assets/player/explosion2_strip7.png", NewRect(NewPoint(player->Go->position->x,0), player->Go->texture_size), 7, 0.1f);

    Player* player = NewPlayer(NewPoint(290,180), NewSize(65,65),100, 15000, (char*)"./assets/player/myplane_strip3.png");
    AddAnimation(player->Character_, (char*)"main", (char*)"./assets/player/myplane_strip3.png", NewRect(NewPoint(player->Character_->Go->position->x,0), player->Character_->Go->texture_size), 3, 0.03f);
    AddAnimation(player->Character_, (char*)"explosion", (char*)"./assets/player/explosion2_strip7.png", NewRect(NewPoint(player->Character_->Go->position->x,0), player->Character_->Go->texture_size), 7, 0.1f);
    
    InputSystem* inputSystem = NewInputSystem((char*)"wasd");

    List* bullets = NewList();
    GenericAddElemList(bullets, 10, (char*)"bullet", playerBullet);

    List* Islands = NewList();
    GenericAddElemList(Islands, 2, (char*)"island", Normal);
    GenericAddElemList(Islands, 2, (char*)"island", Vulcan);
    GenericAddElemList(Islands, 2, (char*)"island", Sand);

    List* Water = NewList();
    GenericAddElemList(Water, 1, (char*)"background", 0);

    GameObject* ui_bottom = NewGameObject(NewPoint(0,HEIGHT_WINDOW-99), NewSize(WIDTH_WINDOW, 100), (char*)"./assets/ui/bottom.png");

    boolean done = false;   
    while (!done) {
        SDL_RenderClear(renderer);
        SDL_Event event;

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

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
                break;
            }
            else UpdateInputSystem(&event, inputSystem, player->Character_, delta_time, bullets);
        }
        
        // BACKGROUND
        RenderGameObjectList(renderer, Water, true, delta_time);
        RenderGameObjectList(renderer, Islands, false, delta_time);

        UpdateBullets(renderer, bullets, delta_time);
        
        //UpdateCharacter(renderer, player, delta_time);
        //RenderingThisAnimation(renderer, player->Character_->Animator_, (char*)"explosion", player->Character_->Go->position, delta_time);

        // UI BASE
        RenderGameObject(renderer, ui_bottom);

        // LIFES
        UpdatePlayer(renderer, player, delta_time);
        // RenderGameObject(renderer, life1);
        // RenderGameObject(renderer, life2);
        // RenderGameObject(renderer, life3);

        // Blit
        SDL_RenderPresent(renderer);
    }

    //Clean Up
    CloseWindow(renderer, window);

    // DestroyGameObject(life1);
    // DestroyGameObject(life2);
    // DestroyGameObject(life3);
    DestroyGameObject(ui_bottom);
    //DestroyGameObject(background);

    DestroyList(bullets);
    DestroyPlayer(player);
    //DestroyCharacter(player);
    DestroyInputSystem(inputSystem);

    return 0;
}