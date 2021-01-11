#ifndef UI_H
#define UI_H

#include "common.h"
#include "renderer.h"

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

// INTERFACE
Interface* NewInterface();
void AddUiList(Interface*, Point*, Size*, char*);
void UpdateInterface(SDL_Renderer*, Interface*, double);
void DestroyInterface(Interface* i);

// UI
UI* NewUI(Point*, Size*, char*);
void RenderingUI(SDL_Renderer* renderer, UI* ui);
void DestroyUI(UI* ui);

#endif // UI_H