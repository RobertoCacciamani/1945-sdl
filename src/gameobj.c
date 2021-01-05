#include "gameobj.h"

void NewGameObject(GameObject* go, point pos, size texture_size, char* texture_path){
    go->position = pos;
    go->texture_path = texture_path;
    go->texture_size = texture_size;
}

void RenderGameObject(SDL_Renderer* render, GameObject* go){
    SDL_Texture* texture = NewTexture(render, go->texture_path);
    RenderingTexture(render, texture, go->position, go->texture_size);
    SDL_DestroyTexture(texture);
    //SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "render_bullet: %f, %f", go->position.x, go->position.y);
}
