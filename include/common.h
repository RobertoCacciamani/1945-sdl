#ifndef COMMON_H
#define COMMON_H

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

Size NewSize(float, float);
Point NewPoint(float, float);

void DestroySize(Size*);
void DestroyPoint(Point*);

#endif // COMMON_H