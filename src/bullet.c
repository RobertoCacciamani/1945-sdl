#include "bullet.h"

Bullet NewBullet(BulletType bulletType){
    Bullet bullet_;
    if (bulletType == playerBullet)
    {
        bullet_.Damage = 30;
        bullet_.Speed = 100;
        bullet_.IsActive = false;
        bullet_.Go.position = NewPoint(20,20);
        bullet_.Go.texture_path = "./assets/player/bullet.png";
        bullet_.Go.texture_size = NewSize(10,10); // in base alla texture usata cambia la size
        //NewGameObject(&bullet_.Go, *p, NewSize(10,10) ,"playerbullet");
    }
    else if (bulletType == enemyBullet)
    {
        bullet_.Damage = 20;
        bullet_.Speed = -10;   
        bullet_.IsActive = false;
        bullet_.Go.position = NewPoint(20,20);
        bullet_.Go.texture_path = "./assets/enemy/enemybullet1.png";
        bullet_.Go.texture_size = NewSize(10,10); // in base alla texture usata cambia la size
    }
    else if (bulletType == normal)
    {
        bullet_.Damage = 10;
        bullet_.Speed = 10;
        bullet_.IsActive = false;
        bullet_.Go.position = NewPoint(20,20);
        bullet_.Go.texture_path = "./assets/enemy/enemybullet2.png";
        bullet_.Go.texture_size = NewSize(10,10); // in base alla texture usata cambia la size
    }
    return bullet_;
}

void RenderingBullets(SDL_Renderer* renderer, List* bullets, float delta_time){
    int count = 0;
    Node* each = bullets->__head;
    Bullet* bullet_free;
    while (each)
    {
        Node* next = each->next;
        if (((Bullet*)each->data)->IsActive){
            bullet_free = (Bullet*)each->data;
            bullet_free->Go.position.y += -1 * bullet_free->Speed * delta_time;
            RenderingBullet(renderer, bullet_free);
            //printf("shooted bullet [%d]\n", count);
        }
        count++;
        each = next;
    }
}

void RenderingBullet(SDL_Renderer* renderer, Bullet* b){
    //printf("bullet is active\n");
    //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "render_bullet: %f, %f", b->Go.position.x, b->Go.position.y);
    if (b->Go.position.y < 0)
    {
        b->IsActive = false; // only with list in config
        //free(b);
    }
    else{
        //printf("rendering bullet\n");
        RenderGameObject(renderer, &b->Go);        
    }
}
