#include <renderer.h>

int RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, point p, size s){
    SDL_Rect rect;
    NewRect(&rect, p, s);
    return SDL_RenderCopy(r, tex, NULL, &rect);
}

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file){
    return (SDL_Texture*)IMG_LoadTexture(renderer, path_file); 
}

void NewRect(SDL_Rect* texture_rect, point p, size s){
    texture_rect->x = p.x;
    texture_rect->y = p.y; 
    texture_rect->w = s.Width; 
    texture_rect->h = s.Height;
}

void NewRect_with_param(SDL_Rect* texture_rect, float x, float y, float width, float height){
    texture_rect->x = x;
    texture_rect->y = y; 
    texture_rect->w = width; 
    texture_rect->h = height;
}

void CloseWindow(SDL_Renderer* r, SDL_Window* win){
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(win);  
    SDL_Quit();
}

