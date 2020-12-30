#include <renderer.h>

void RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, const SDL_Rect* rect){
    SDL_RenderCopy(r, tex, NULL, rect);
}

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file){
    return (SDL_Texture*)IMG_LoadTexture(renderer, path_file); 
}

SDL_Rect* NewRect(point p, size s){
    SDL_Rect texture_rect;
    texture_rect.x = p.x;
    texture_rect.y = p.y; 
    texture_rect.w = s.Width; 
    texture_rect.h = s.Height;
    return &texture_rect;
}

SDL_Rect* NewRect_with_param(float x, float y, float width, float height){
    SDL_Rect texture_rect;
    texture_rect.x = x;
    texture_rect.y = y; 
    texture_rect.w = width; 
    texture_rect.h = height;
    return &texture_rect;
}

void CloseWindow(SDL_Renderer* r, SDL_Window* win){
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(win);  
    SDL_Quit();
}

