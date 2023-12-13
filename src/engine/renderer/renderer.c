#include "../../../include/engine/renderer/renderer.h"

const int RENDERER_OBJECT_DYNAMIC_ARRAY_CHUNK_SIZE = 16;

Renderer* Renderer_Create(Size2 screenSize) {
    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        free(renderer);
        exit(1);
        return NULL;
    }

    renderer->window = Window_Create(screenSize);
    if (renderer->window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        free(renderer);
        exit(1);
        return NULL;
    }

    renderer->renderer = SDL_CreateRenderer(renderer->window->_window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer->renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        free(renderer);
        exit(1);
        return NULL;
    }

    renderer->rendererObjects = (RendererObject*)malloc(RENDERER_OBJECT_DYNAMIC_ARRAY_CHUNK_SIZE * sizeof(RendererObject));

    //renderer->physics = Physics_init();

    return renderer;

}

void Renderer_Destroy(Renderer* renderer) {
    // Implémentez la fonction de destruction ici
}

void Renderer_Clear(Renderer* renderer) {
    RGBA blackColor = {0, 0, 0, 255};
    SDL_SetRenderDrawColor(renderer->renderer, blackColor.r, blackColor.g, blackColor.b, blackColor.a);
    SDL_RenderClear(renderer->renderer);
}

// never called 
void Renderer_Present(Renderer* renderer) {
    SDL_RenderPresent(renderer->renderer);
}


void Renderer_DrawBackground(Renderer* renderer, RGBA color){
    SDL_SetRenderDrawColor(renderer->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer->renderer);
}


void Renderer_DrawPolygon(Renderer* renderer, bool isFillIn, Object object)
{
    Polygone polygone = *object.polygone;

    // add world position to all points
    SDL_Point* points = (SDL_Point*)malloc(polygone.pointsCount * sizeof(SDL_Point));
    for(int i = 0; i < polygone.pointsCount; i++)
    {
        points[i].x = polygone.points[i].x + object.transform.position.x;
        points[i].y = polygone.points[i].y + object.transform.position.y;
    }

    SDL_SetRenderDrawColor(renderer->renderer, polygone.color.r, polygone.color.g, polygone.color.b, polygone.color.a);
    SDL_RenderDrawLines(renderer->renderer, points, polygone.pointsCount);
    if(isFillIn)
    {
        Renderer_FillPolygon(renderer->renderer, points, polygone.pointsCount);
    }

    free(points);
}

void Renderer_FillPolygon(SDL_Renderer* renderer, SDL_Point* points, int numPoints) {
    if (numPoints < 3) 
    {
        return;
    }

    int* xs = (int*)malloc(numPoints * sizeof(int));
    for (int i = 0; i < numPoints; i++) 
    {
        xs[i] = points[i].x;
    }

    int minY = points[0].y;
    int maxY = points[0].y;

    for (int i = 1; i < numPoints; i++)
     {
        if (points[i].y < minY) 
        {
            minY = points[i].y;
        }
        if (points[i].y > maxY) 
        {
            maxY = points[i].y;
        }
    }

    for (int y = minY; y <= maxY; y++) 
    {
        int n = 0;
        for (int i = 0, j = numPoints - 1; i < numPoints; j = i++) 
        {
            int yi = points[i].y;
            int yj = points[j].y;
            if ((yi < y && yj >= y) || (yj < y && yi >= y)) {
                int xi = points[i].x;
                int xj = points[j].x;
                xs[n++] = (int)(xi + (y - yi) * (xj - xi) / (float)(yj - yi));
            }
        }

        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (xs[j] > xs[j + 1]) {
                    int temp = xs[j];
                    xs[j] = xs[j + 1];
                    xs[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i += 2) {
            SDL_RenderDrawLine(renderer, xs[i], y, xs[i + 1], y);
        }
    }

    free(xs);
}

//texture
    /* SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer->renderer, surface);

    if(texture == NULL){
        printf("Error creating texture from surface: %s\n", SDL_GetError());
        RGBA redColor = {255, 0, 0, 255};
        Renderer_DrawRectangle(renderer, x, y, width, height, redColor);
    }

    SDL_RenderCopy(renderer->renderer, texture, NULL, &rect);*/
    // impossible a tester pour le moment mais normalement pas besoin d'appler cette fonction



void Renderer_AddObjectToRender(Renderer* renderer, Object* object, int zIndex)
{
    bool isMaxSizeReached = renderer->rendererObjectsCount % RENDERER_OBJECT_DYNAMIC_ARRAY_CHUNK_SIZE == 0;

    if(isMaxSizeReached)
    {
        DynamicArray_realloc((void**)&renderer->rendererObjects, sizeof(RendererObject), renderer->rendererObjectsCount + RENDERER_OBJECT_DYNAMIC_ARRAY_CHUNK_SIZE);
    }
    renderer->rendererObjects[renderer->rendererObjectsCount].object = object;
    renderer->rendererObjects[renderer->rendererObjectsCount].zIndex = zIndex;
    renderer->rendererObjectsCount++;
}

void Renderer_OrderOjectdByzIndex(Renderer* renderer)
{
    // sort objects by z index
    for(int i = 0; i < renderer->rendererObjectsCount; i++)
    {
        for(int j = 0; j < renderer->rendererObjectsCount - i - 1; j++)
        {
            if(renderer->rendererObjects[j].zIndex > renderer->rendererObjects[j + 1].zIndex)
            {
                RendererObject temp = renderer->rendererObjects[j];
                renderer->rendererObjects[j] = renderer->rendererObjects[j + 1];
                renderer->rendererObjects[j + 1] = temp;
            }
        }
    }
}

void Renderer_Render(Renderer* renderer)
{
    Renderer_OrderOjectdByzIndex(renderer);
    
    for(int i = 0; i < renderer->rendererObjectsCount; i++)
    {
        Renderer_DrawPolygon(renderer, renderer->rendererObjects[i].object->polygone->isFillIn, *renderer->rendererObjects[i].object);
    }
    SDL_RenderPresent(renderer->renderer);

    Renderer_ClearObjects(renderer);


}

void Renderer_ClearObjects(Renderer* renderer)
{
    renderer->rendererObjectsCount = 0;
}