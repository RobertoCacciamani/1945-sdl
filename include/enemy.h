#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

typedef struct
{
    Character* Character_;
    int score;
    boolean IsAlive;
    boolean IsDead;
} Enemy;

typedef struct
{
    List* enemys;
} EnemyManager;


// ENEMY MANAGER
EnemyManager* NewEnemyManager();
void AddEnemyManagerList(EnemyManager*, Size*, char*);
void UpdateEnemyManager(SDL_Renderer*, EnemyManager*, double);
void DestroyEnemyManager(EnemyManager*);

// ENEMY
Enemy* NewEnemy(Size* s, char* texture);
void UpdateEnemy(SDL_Renderer*, Enemy*, double);
void DestroyEnemy(Enemy*);

void RespawnEnemy(Enemy* enemy);

void AI(Enemy* enemy, double dt);

#endif // ENEMY_H
