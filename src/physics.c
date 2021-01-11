#include "physics.h"

PhysicsManager* NewPhysicsManager(Player* p, EnemyManager* enemymgr){
    PhysicsManager* pm = (PhysicsManager*)calloc(1, sizeof(PhysicsManager));
    pm->player = p;
    pm->enemymgr = enemymgr;
    return pm;
}

void DestroyPhysicsManager(PhysicsManager* pm){
    free(pm);
}

void CheckCollision(PhysicsManager* pm){
    CheckCollisionPlayerEnemy(pm);
    CheckCollisionPlayerBullets(pm);
}

void CheckCollisionPlayerEnemy(PhysicsManager* pm){
    Player* player = pm->player;
    Node* each = pm->enemymgr->enemys->__head;
    Enemy* enemy;
    while (each)
    {
        Node* next = each->next;
        enemy = (Enemy*)each->data;
        if (player->IsAlive && enemy->IsAlive)
        {
            if(CheckCollisionPoint(player->Character_->Go, enemy->Character_->Go)){
            //if(SDL_HasIntersection(player->Character_->Go->MyRect, enemy->Character_->Go->MyRect)){
                int player_hp = player->Character_->Hp;
                player->Character_->Hp -= enemy->Character_->Hp;
                enemy->Character_->Hp -= player_hp;
                break;
            }
        }
        each = next;
    }
}

void CheckCollisionPlayerBullets(PhysicsManager* pm){
    Node* each = pm->player->Character_->bullets->__head;
    Bullet* bullet;
    while (each)
    {
        Node* next = each->next;
        bullet = (Bullet*)each->data;
        if (bullet->Go->IsActive == true)
        {
            // printf("bullet x: %f y: %f \n", bullet->Go->position->x, bullet->Go->position->y);
            //if(SDL_HasIntersection(NewRect(), NewRect()))

            CheckCollisionPlayerBulletEnemy(pm, bullet);
        }
        each = next;
    }
}

void CheckCollisionPlayerBulletEnemy(PhysicsManager* pm, Bullet* bullet){
    Node* each = pm->enemymgr->enemys->__head;
    Enemy* enemy;
    while (each)
    {
        Node* next = each->next;
        enemy = (Enemy*)each->data;
        if (enemy->IsAlive && !enemy->IsDead && enemy->Character_->Go->position->y > 0)
        {
            //if(SDL_IntersectRect(bullet->Go->MyRect, enemy->Character_->Go->MyRect, RECTZERO)){
            //if(SDL_HasIntersection(bullet->Go->MyRect, enemy->Character_->Go->MyRect)){
            if(CheckCollisionPoint(enemy->Character_->Go, bullet->Go)){
                printf("collision bullet_enemy\n");
                bullet->Go->IsActive = false;
                enemy->Character_->Hp -= bullet->Damage;
                break;
            }
        }
        each = next;
    }
}

boolean CheckCollisionPoint(GameObject* player, GameObject* enemy){
    Point* enemy_min = enemy->position;
    Point* enemy_max = GetMaxPointGameObject(enemy);
    // printf("\n\n--------------\nenemy_min x: %f y: %f \n", enemy_min->x, enemy_min->y);
    // printf("enemy_max x: %f y: %f \n--------------\n\n", enemy_max->x, enemy_max->y);
    if (PointInRect(enemy_min, player) || PointInRect(enemy_max, player) || PointInRect(NewPoint(enemy_max->x, enemy_min->y), player) || PointInRect(NewPoint(enemy_min->x, enemy_max->y), player))
    {
        printf("collisione player_to_enemy\n");
        return true;
    }
    else {
        return false;
    }
}

boolean PointInRect(Point* p, GameObject* go){
    Point* min = go->position;
    Point* max = GetMaxPointGameObject(go);
    // printf("bullet_min x: %f y: %f \n", min->x, min->y);
    // printf("bullet_max x: %f y: %f \n", max->x, max->y);
    if (p->x >= min->x && p->y >= min->y)
    {
        if (p->x <= max->x && p->y <= max->y)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

Point* GetMaxPointGameObject(GameObject* go){
    return NewPoint(go->position->x + go->texture_size->Width, go->position->y + go->texture_size->Height);
}