#include "enemy.h"

Enemy* NewEnemy(Size* s, char* texture){
    Enemy* enemy = (Enemy*)calloc(1, sizeof(Enemy));
    enemy->Character_ = NewCharacter(50, 100, texture, NewPoint(0,0), s);
    enemy->score = 5;
    enemy->IsAlive = true;
    enemy->IsDead = false;
    GenericAddElemList(enemy->Character_->bullets, 10, (char*)"bullet", enemyBullet);
    AddAnimation(enemy->Character_, (char*)"main", texture, NewRect(enemy->Character_->Go->position, NewSize(32,32)), 3, 0.05f);
    AddAnimation(enemy->Character_, (char*)"explosion", (char*)"./assets/enemy/explosion1_strip6.png", NewRect(enemy->Character_->Go->position, NewSize(32,32)), 6, 0.1f);
    enemy->Character_->Go->position->x = GetRandomInRange(100, WIDTH_WINDOW - (100 + s->Width));
    enemy->Character_->Go->position->y = -GetRandomInRange(s->Height, s->Height - 300);
    return enemy;    
}

void UpdateEnemy(SDL_Renderer* renderer, Enemy* enemy, double dt){
    //printf("enemy x: %f y: %f \n", enemy->Character_->Go->position->x, enemy->Character_->Go->position->y);
    //printf("enemy hp: %f\n", enemy->Character_->Hp);
    if(enemy->Character_->Hp > 0 && enemy->Character_->Go->position->y > 0){
        //enemy->Character_->Hp -= 0.03f;
    }
    else if (enemy->Character_->Hp <= 0 && !enemy->IsDead)
    {
        printf("enemy morto!\n");
        enemy->IsAlive = false;
        enemy->Character_->Go->IsActive = false;
        if(RenderingThisAnimation(renderer, enemy->Character_->Animator_, "explosion", enemy->Character_->Go->position, dt)){
            enemy->IsDead = true;
        }
    }

    RespawnEnemy(enemy);

    UpdateCharacter(renderer, enemy->Character_, dt);
}

void RespawnEnemy(Enemy* enemy){
    if(enemy->Character_->Go->position->y >= HEIGHT_WINDOW - 90 || enemy->IsDead){
        enemy->Character_->Go->position->x = GetRandomInRange(100, WIDTH_WINDOW - (100 + enemy->Character_->Go->texture_size->Width));
        enemy->Character_->Go->position->y = -GetRandomInRange(enemy->Character_->Go->texture_size->Height, enemy->Character_->Go->texture_size->Height - 300);
        enemy->IsAlive = true;
        enemy->IsDead = false;
        enemy->Character_->Go->IsActive = true;
        enemy->Character_->Hp = 50;
        printf("enemy rispawnato!\n");
    }
}

void DestroyEnemy(Enemy* e){
    DestroyCharacter(e->Character_);
    free(e);
}

EnemyManager* NewEnemyManager(){
    EnemyManager* enemymgr = (EnemyManager*)calloc(1, sizeof(EnemyManager));
    enemymgr->enemys = NewList();
    return enemymgr;    
}

void DestroyEnemyManager(EnemyManager* enemymgr){
    Node* each = enemymgr->enemys->__head;
    while (each)
    {
        Node* next = each->next;
        DestroyEnemy(((Enemy*)each->data));
        each = next;
    }
    DestroyList(enemymgr->enemys);
    free(enemymgr);
}

void AddEnemyManagerList(EnemyManager* enemymgr, Size* s, char* txt_path){
    AddElemList(enemymgr->enemys, NewEnemy(s, txt_path));
}

void UpdateEnemyManager(SDL_Renderer* renderer, EnemyManager* enemymgr, double dt){
    Node* each = enemymgr->enemys->__head;
    while (each)
    {
        Node* next = each->next;
        AI(((Enemy*)each->data), dt);
        UpdateEnemy(renderer, ((Enemy*)each->data), dt);
        each = next;
    }
}

void AI(Enemy* enemy, double dt){
    enemy->Character_->Go->position->y += enemy->Character_->Speed * dt;
}