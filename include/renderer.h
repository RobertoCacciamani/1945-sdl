#ifndef RENDERER_H
#define RENDERER_H

#include "common.h"

typedef struct 
{
    List* Animations;
} Animator;

typedef struct 
{
    char* Name;
    int TotFrames;
    int currFrame;
    char* texture_path;
    double TimeFrame;
    double DelayFrame;
    Size* FrameSize;
    List* list;
} Animation;

// texture
int RenderingTexture(SDL_Renderer*, SDL_Texture*, Point*, Size*);
int RenderingPath(SDL_Renderer*, char*, Point*, Size*);
SDL_Texture* NewTexture(SDL_Renderer*, char*);
SDL_Rect* NewRect(Point*, Size*);
void DestroyRect(SDL_Rect*);

// animation
Animator* NewAnimator();
void DestroyAnimator(Animator*);
Animation* NewAnimation(char*, char*, SDL_Rect*, int, double);
void DestroyListAnimation(List*);
void DestroyAnimation(Animation*);

boolean RenderingThisAnimation(SDL_Renderer*, Animator*, char*, Point*, double);
boolean RenderingListAnimation(SDL_Renderer*, Animation*, SDL_Rect*, double);
void RenderingAnimation(SDL_Renderer*, char*, SDL_Rect*, SDL_Rect*);

// window
void CloseWindow(SDL_Renderer*, SDL_Window*);

#endif // RENDERER_H