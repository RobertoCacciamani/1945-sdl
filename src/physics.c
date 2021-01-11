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
                int player_hp = player->Character_->Hp;
                player->Character_->Hp -= enemy->Character_->Hp;
                enemy->Character_->Hp -= player_hp;
                break;
            }
        }
        each = next;
    }
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
                int player_hp = player->Character_->Hp;
                player->Character_->Hp -= enemy->Character_->Hp;
                enemy->Character_->Hp -= player_hp;
                break;
            }
        }
        each = next;
    }
}

boolean CheckCollisionPoint(GameObject* player, GameObject* enemy){
    Point* enemy_min = enemy->position;
    Point* enemy_max = GetMaxPointGameObject(enemy);
    if (PointInRect(enemy_min, player) || PointInRect(enemy_max, player))
    {
        printf("collisione player_to_enemy\n");
        return true;
    }
    else{
        return false;
    }
}

boolean PointInRect(Point* p, GameObject* go){
    Point* min = go->position;
    Point* max = GetMaxPointGameObject(go);
    if (p->x > min->x && p->y > min->y)
    {
        if (p->x < max->x && p->y < max->y)
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