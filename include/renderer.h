#ifndef RENDERER_H
#define RENDERER_H
#include "common.h"

int RenderingTexture(SDL_Renderer* r, SDL_Texture* tex, Point p, Size s);

SDL_Texture* NewTexture(SDL_Renderer* renderer, char* path_file);

//void NewRect(SDL_Rect* rect_, Point p, Size s);

void CloseWindow(SDL_Renderer* r, SDL_Window* win);


#endif // RENDERER_H