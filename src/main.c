//Per dire a SDL che si usera' il proprio main applicativo.
//Altrimenti SDL cerca di caricare il main da SDL2Main.lib
//NOTA: Si può passare anche come argomento di compilazione con -D
#define SDL_MAIN_HANDLED
#include <common.h>
#include <renderer.h>
#include <gameobj.h>
#include <input.h>


int main() {
    SDL_Init(SDL_INIT_VIDEO);

    size win = NewSize(640, 480);

    SDL_Window* window = SDL_CreateWindow(
        "1945",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        win.Width,
        win.Height,
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
    float time_counter = 0.f;
    
    // GameObject player;
    
    // NewGameObject(&player, NewPoint(10,10), NewSize(50,50), "./assets/ui/life.png");
    
    Character player;
    newCharacter(&player, 100, 10000, "./assets/ui/life.png", NewPoint(20,20), NewSize(50,50));

    InputSystem inputSystem;
    InitInputSystem(&inputSystem, "wasd");

    SDL_Rect texture_rect;
    texture_rect.x = 10;
    texture_rect.y = 10; 
    texture_rect.w = 50; 
    texture_rect.h = 50;

    SDL_Texture* texture_app = NewTexture(renderer, "./assets/ui/life.png");
    SDL_Texture* texture_base_ui = NewTexture(renderer, "./assets/ui/bottom.png");


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
            Movement(&event, &inputSystem, &player, &delta_time);
        }
        
        //RenderGameObject(renderer, &player);
        RenderCharacter(renderer, &player);
        
        // UI BASE
        RenderingTexture(renderer, texture_base_ui, NewPoint(0,win.Height-99), NewSize(win.Width, 100));
        
        // LIFES
        RenderingTexture(renderer, texture_app, NewPoint(100,win.Height-90), NewSize(40, 40));
        RenderingTexture(renderer, texture_app, NewPoint(55,win.Height-90), NewSize(40, 40));
        RenderingTexture(renderer, texture_app, NewPoint(10,win.Height-90), NewSize(40, 40));
        

        
        // Clear
        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        //SDL_RenderClear(renderer);
        
        // Blit
        SDL_RenderPresent(renderer);
    }

    //Clean Up
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);  
    // SDL_Quit();
    CloseWindow(renderer, window);

    return 0;
}