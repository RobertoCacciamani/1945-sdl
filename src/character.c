#include <character.h>

// #define BULLET_SINGLE "path_single"
// #define BULLET_DOUBLE "path_double"
// #define BULLET_ENEMY "path_enemy"

Character* NewCharacter(int hp, float speed, char* path, Point p, Size s){
    Character* c = (Character*)calloc(1, sizeof(Character));
    c->Hp = hp;
    c->Speed = speed;
    c->Go = NewGameObject(p, s, path);
    return c;
}

void DestroyCharacter(Character* c){
    DestroyGameObject(c->Go);
    free(c);
}

void RenderCharacter(SDL_Renderer* render, Character* c){
    RenderGameObject(render, c->Go);
}
