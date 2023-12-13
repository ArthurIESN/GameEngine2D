#include "../../../include/game_content/platform/platform.h"
//#include "../../../include/engine/renderer/renderer.h"

#include <SDL.h>
#include <SDL_image.h>


Platform* Platform_init(void){
    Platform* platform = (Platform*)malloc(sizeof(Platform));
    if (platform == NULL) {
        perror("Failed to allocate memory for platform");
        exit(1);
    }

    platform->rectangle = BasicShapes_InitRectangle(50, 50, (Vector2){100, 100}, (RGBA){255, 255, 255, 255}, true);
    
    
    platform->texturePath = (char*)malloc(strlen("../../textures/platform/platform_texture.png") + 1);
    if (platform->texturePath == NULL) {
        perror("Failed to allocate memory for texturePath");
        free(platform);
        exit(1);
    }
    strcpy(platform->texturePath, "/textures/platform/platform_texture.png");

    SDL_Surface* surface = Platform_initSurface(platform);
    platform->surface = surface;

    printf("initPlatform\n");
    return platform;
}

SDL_Surface* Platform_initSurface(Platform* platform){
    SDL_Surface* surface;
    surface = IMG_Load(platform->texturePath);
   

    if(surface == NULL){
        printf("Error loading platform texture: %s\n", SDL_GetError());
    }

    printf("initPlatformSurface\n");
    return surface;
}

void Platform_initPoints(Platform* platform, SDL_Point points[], int pointsCount){
    platform->rectangle->object->polygone->pointsCount = pointsCount;
    platform->rectangle->object->polygone->points = points;
}

void Platform_Draw(Platform* platform, Renderer* renderer)
{
    Renderer_DrawPolygon(renderer, true, *platform->rectangle->object);
}

