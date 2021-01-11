#ifndef PHYSICS_H
#define PHYSICS_H

#include <common.h>
#include <player.h>
#include <enemy.h>

typedef struct
{
    Player* player;
    EnemyManager* enemymgr;
} PhysicsManager;

PhysicsManager* NewPhysicsManager(Player*, EnemyManager*);
void DestroyPhysicsManager(PhysicsManager*);

void CheckCollision(PhysicsManager* pm);
void CheckCollisionPlayerEnemy(PhysicsManager* pm);
Point* GetMaxPointGameObject(GameObject* go);
boolean CheckCollisionPoint(GameObject* go1, GameObject* go2);
boolean PointInRect(Point* p, GameObject* go);
#endif // PHYSICS_H