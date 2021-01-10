#ifndef BULLET_H
#define BULLET_H

#include "common.h"
#include "gameobj.h"
#include "renderer.h"


typedef struct
{
    GameObject* Go;
    int Damage;
    float Speed;
} Bullet;

enum BulletType_ {normal = 0, playerBullet, enemyBullet};
typedef enum BulletType_ BulletType; 

Bullet* NewBullet(BulletType);
void RenderingBullet(SDL_Renderer*, Bullet*);
void UpdateBullets(SDL_Renderer*, List*, double);

void DestroyBullet(Bullet*);


#endif /*BULLET_H*/