#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren)
{
    SDL_Surface* temporarySurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, temporarySurface);
    SDL_FreeSurface(temporarySurface);

    return tex;
}