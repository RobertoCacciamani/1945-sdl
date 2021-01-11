#ifndef COMMON_H
#define COMMON_H

#define HEIGHT_WINDOW 480
#define WIDTH_WINDOW 640
#define RECTZERO NewRect(NewPoint(0,0), NewSize(0,0))

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

enum boolean_enum { false, true };
typedef unsigned char boolean;

typedef unsigned int uint;

typedef struct {
    float Width;
    float Height;
} Size;

typedef struct {
    float x;
    float y;
} Point;

Size* NewSize(float, float);
Point* NewPoint(float, float);

int GetRandomInRange(int, int);
Point* RandomPoint(Size*);

void DestroySize(Size*);
void DestroyPoint(Point*);


#endif // COMMON_H