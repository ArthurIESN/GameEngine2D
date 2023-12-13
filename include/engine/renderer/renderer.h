#ifndef RENDERER_H
#define RENDERER_H


#include <SDL.h>

#include <engine/window/window.h>
#include <engine/physics/physics.h>
#include <engine/components/dynamicArray.h>
#include <structs/structs.h>

extern const int RENDERER_OBJECT_DYNAMIC_ARRAY_CHUNK_SIZE;

typedef struct {
    SDL_Renderer* renderer;
    Physics* physics;
    Window* window;
    RendererObject* rendererObjects; // all object to draw on the screen + order
    int rendererObjectsCount;
} Renderer;

Renderer* Renderer_Create(Size2 screenSize);
void Renderer_Destroy(Renderer* renderer);
void Renderer_Clear(Renderer* renderer);
void Renderer_Present(Renderer* renderer);



// Drawing functions
/*
@brief Draw the background of the window
@param renderer The renderer
@param color The color of the background
*/
void Renderer_DrawBackground(Renderer* renderer, RGBA color);
/*
@brief Draw a polygon on the window
@param renderer The renderer
@param isFillIn If true, the polygon will be filled in otherwise it will be drawn as a line
@param polygone The polygon to draw
*/
void Renderer_DrawPolygon(Renderer* renderer, bool isFillIn, Object object);
/*
@brief Draw a filled polygon on the window
@param renderer The renderer
@param polygone The polygon to draw
*/
void Renderer_FillPolygon(SDL_Renderer* renderer, SDL_Point* points, int numPoints);

void Renderer_AddObjectToRender(Renderer* renderer, Object* object, int zIndex);
void Renderer_OrderOjectdByzIndex(Renderer* renderer);
void Renderer_Render(Renderer* renderer);
void Renderer_ClearObjects(Renderer* renderer);

#endif
