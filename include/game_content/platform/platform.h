
#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>

#include <engine/physics/collider.h>
#include <engine/renderer/renderer.h>
#include <engine/basicShapes/basicShapes.h>
#include <structs/structs.h>

typedef struct{
    SDL_Surface* surface;
    SDL_Texture* texture;
    char* texturePath;
    BasicShapes_Rectangle* rectangle;
} Platform; 

Platform* Platform_init(void);
SDL_Surface* Platform_initSurface(Platform* platform);
void Platform_initPoints(Platform* platform, SDL_Point points[], int pointsCount);

void Platform_Draw(Platform* platform, Renderer* renderer);






#endif