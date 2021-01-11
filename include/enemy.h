#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "input.h"

typedef struct
{
    Character* Character_;
    int score;
    //float DelayShoot;
    float TimeShoot;
    boolean IsAlive;
    boolean IsDead;
} Enemy;

typedef struct
{
    List* enemys;
} EnemyManager;


// ENEMY MANAGER
EnemyManager* NewEnemyManager();
void AddEnemyManagerList(EnemyManager*, Size*, char*, int);
void UpdateEnemyManager(SDL_Renderer*, EnemyManager*, double);
void DestroyEnemyManager(EnemyManager*);

// ENEMY
Enemy* NewEnemy(Size*, char*, int);
void UpdateEnemy(SDL_Renderer*, Enemy*, double);
void RespawnEnemy(Enemy*);
void ShootEnemy(Enemy*, double);
void AI(Enemy*, double);
void DestroyEnemy(Enemy*);



#endif // ENEMY_H
