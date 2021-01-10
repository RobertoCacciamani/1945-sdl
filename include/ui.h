#ifndef UI_H
#define UI_H

#include "common.h"
#include "renderer.h"
#include "player.h"

typedef struct 
{
    List* UiList;
} Interface;

typedef struct 
{
    char* txt_path;
    Point* position;
    Size*  size;
} UI;

Interface* NewInterface();

void AddUiList(Interface*, Point*, Size*, char*);

UI* NewUI(Point*, Size*, char*);

void UpdateInterface(SDL_Renderer*, Interface*, Player*, double);

void RenderingUI(SDL_Renderer* renderer, UI* ui);

void DestroyUI(UI* ui);

#endif // UI_H