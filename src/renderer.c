#include <renderer.h>

int RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, Point p, Size s){
    SDL_Rect rect;
    rect.x = p.x;
    rect.y = p.y; 
    rect.w = s.Width; 
    rect.h = s.Height;
    //SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);
    return SDL_RenderCopy(r, tex, NULL, &rect);
}

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file){
    return (SDL_Texture*)IMG_LoadTexture(renderer, path_file); 
}

// void NewRect(SDL_Rect* rect_, Point p, Size s){
//     //SDL_FRect* rect_ = (SDL_FRect*)calloc(1, sizeof(SDL_FRect));
//     rect_->x = p.x;
//     rect_->y = p.y; 
//     rect_->w = s.Width; 
//     rect_->h = s.Height;
//     // return rect_;
// }

void CloseWindow(SDL_Renderer* r, SDL_Window* win){
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
