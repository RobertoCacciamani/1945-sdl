#include "gameobj.h"

GameObject* NewGameObject(point pos, size texture_size, char* texture_path){
    GameObject go;
    go.position = pos;
    go.texture_path = texture_path;
    go.texture_size = texture_size;
    go.rect = NewRect(NewPoint(0,0), NewSize(50,50));
    return &go;
}


void RenderGameObject(SDL_Renderer* render, GameObject* go){
    SDL_Texture* texture = NewTexture(render, go->texture_path);  
    RenderingTexture(render, texture, &go->rect);
}
