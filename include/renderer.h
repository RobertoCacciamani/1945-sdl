#ifndef RENDERER_H
#define RENDERER_H
#include "common.h"

int RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, point p, size s);

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file);

SDL_Rect* NewRect(SDL_Rect* texture_rect, point p, size s);

void NewRect_with_param(SDL_Rect* texture_rect, float x, float y, float width, float height);

void CloseWindow(SDL_Renderer* r, SDL_Window* win);


#endif // RENDERER_H