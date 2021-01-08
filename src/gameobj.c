#include "gameobj.h"
#include "bullet.h"

GameObject* NewGameObject(Point pos, Size texture_size, char* texture_path){
    GameObject* go = (GameObject*)calloc(1, sizeof(GameObject));
    go->position = pos;
    go->texture_path = texture_path;
    go->texture_size = texture_size;
    go->IsActive = true;
    return go;
}

void DestroyGameObject(GameObject* go){
    if (go)
    {
        free(go);
    }
}

void RenderGameObject(SDL_Renderer* render, GameObject* go){
    SDL_Texture* texture = NewTexture(render, go->texture_path);
    RenderingTexture(render, texture, go->position, go->texture_size);
    SDL_DestroyTexture(texture);
    //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "render_go: %f, %f", go->position.x, go->position.y);
}

void GenericAddElemList(List* l, int n, char* elem, int type){
    if (!strcmp("bullet", elem))
    {
        for (int i = 0; i < n; i++)
        {
            AddElemList(l, NewBullet((BulletType)type));
            //printf("bullet[%d][%d]\n", i, type);
        }   
    }
    else if (!strcmp("island", elem)){
        for (int i = 0; i < n; i++)
        {
            AddElemList(l, NewBullet((BulletType)type));
        }
    }
}

// void elemInList(List* l, int n){//, void* (struct_ptr), void* (function_ptr)()){
//     for (int i = 0; i < n; i++)
//     {
//         Bullet bullet = NewBullet(playerBullet);
//         AddElemList(l, &bullet);
//     }
// }
