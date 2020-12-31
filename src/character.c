#include <character.h>

#define BULLET_SINGLE "path_single"
#define BULLET_DOUBLE "path_double"
#define BULLET_ENEMY "path_enemy"

void newCharacter(character* c, int hp, float speed, char* path, point p, size s){
    c->Hp = hp;
    c->Speed = speed;
    c->Name = path;
    NewGameObject(&c->Go, p, s, path);
}
