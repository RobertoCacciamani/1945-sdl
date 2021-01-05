#ifndef BULLET_H
#define BULLET_H

#include "common.h"
#include "gameobj.h"
#include "renderer.h"
#include "list.h"


typedef struct
{
    GameObject Go;
    int Damage;
    float Speed;
    boolean IsActive;
} Bullet;

enum BulletType_ {normal = 0, playerBullet, enemyBullet};
typedef enum BulletType_ BulletType; 

Bullet NewBullet(BulletType bulletType);
void RenderingBullet(SDL_Renderer* renderer, Bullet* b);
void RenderingBullets(SDL_Renderer* renderer, List* bullets, float delta_time);

#endif /*BULLET_H*/