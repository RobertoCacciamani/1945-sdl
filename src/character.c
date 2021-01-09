#include <character.h>

// #define BULLET_SINGLE "path_single"
// #define BULLET_DOUBLE "path_double"
// #define BULLET_ENEMY "path_enemy"

Character* NewCharacter(int hp, float speed, char* path, Point* p, Size* s){
    Character* c = (Character*)calloc(1, sizeof(Character));
    c->Hp = hp;
    c->Speed = speed;
    c->Go = NewGameObject(p, s, path);
    c->Animator_ = NewAnimator();
    return c;
}

void AddAnimation(Character* c, char* animation_name, char* texture_name, SDL_Rect* rect, int frames){
    Animation* anim = NewAnimation(animation_name, texture_name, rect, frames);
    AddElemList(c->Animator_->Animations,  anim);
}

void RenderCharacter(SDL_Renderer* render, Character* c){
    //RenderGameObject(render, c->Go);
    RenderingThisAnimation(render, c->Animator_, "main", c->Go->position);
}

void DestroyCharacter(Character* c){
    DestroyGameObject(c->Go);
    free(c);
}
