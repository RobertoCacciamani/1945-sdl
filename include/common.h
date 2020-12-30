#ifndef COMMON_H
#define COMMON_H

#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

enum boolean_enum { false, true };
typedef unsigned char boolean;

typedef struct {
    float Width;
    float Height;
} size;

typedef struct {
    float x;
    float y;
} point;

size NewSize(float width, float height);

point NewPoint(float x, float y);


#endif // COMMON_H