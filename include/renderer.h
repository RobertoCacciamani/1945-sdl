#ifndef RENDERER_H
#define RENDERER_H
#include "common.h"

void RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, const SDL_Rect* rect);

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file);

SDL_Rect* NewRect(point p, size s);

SDL_Rect* NewRect_with_param(float x, float y, float width, float height);

void CloseWindow(SDL_Renderer* r, SDL_Window* win);


#endif // RENDERER_H