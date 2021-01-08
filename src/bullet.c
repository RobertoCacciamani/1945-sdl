#include "bullet.h"

Bullet* NewBullet(BulletType bulletType){
    Bullet* bullet_ = (Bullet*)calloc(1, sizeof(Bullet));
    //printf("mo ce provo %d\n", bulletType);
    if (bulletType == playerBullet)
    {
        //printf("bullet preso\n");
        bullet_->Damage = 30;
        bullet_->Speed = 100;
        bullet_->Go = NewGameObject(NewPoint(20,20), NewSize(15,15), "./assets/player/bullet.png");
        bullet_->Go->IsActive = false;
        //printf("ce so riuscito\n");
    }
    else if (bulletType == enemyBullet)
    {
        bullet_->Damage = 20;
        bullet_->Speed = -10;
        bullet_->Go = NewGameObject(NewPoint(20,20), NewSize(10,10), "./assets/enemy/enemybullet1.png");
        bullet_->Go->IsActive = false;
    }
    else if (bulletType == normal)
    {
        bullet_->Damage = 10;
        bullet_->Speed = 10;
        bullet_->Go = NewGameObject(NewPoint(20,20), NewSize(10,10), "./assets/enemy/enemybullet2.png");
        bullet_->Go->IsActive = false;
    }
    return bullet_;
}

void DestroyBullet(Bullet* b){
    DestroyGameObject(b->Go);
    free(b);
}

void RenderingBullets(SDL_Renderer* renderer, List* bullets, float delta_time){
    int count = 0;
    Node* each = bullets->__head;
    Bullet* bullet_free;
    // printf("i tried\n");
    while (each)
    {
        Node* next = each->next;
        //printf("bullet[%d] is active -> %d\n", count, ((Bullet*)each->data)->Go->IsActive);
        if (((Bullet*)each->data)->Go->IsActive == true){
            bullet_free = (Bullet*)each->data;
            bullet_free->Go->position.y += -1 * bullet_free->Speed * delta_time;
            RenderingBullet(renderer, bullet_free);
            //printf("shooted bullet [%d]\n", count);
        }
        count++;
        each = next;
    }
}

void RenderingBullet(SDL_Renderer* renderer, Bullet* b){
    // printf("bullet is active\n");
    //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "render_bullet: %f, %f", b->Go->position->x, b->Go->position->y);
    if (b->Go->position.y < 0)
    {
        b->Go->IsActive = false; // only with list in config
        //free(b);
    }
    else{
        // printf("rendering bullet\n");
        RenderGameObject(renderer, b->Go);        
    }
}
