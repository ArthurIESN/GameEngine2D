#ifndef COLLIDER_H
#define COLLIDER_H

#include <stdbool.h>

#include <engine/renderer/renderer.h>
#include <structs/structs.h>


#include <SDL.h>


bool Collider_checkCollision(Renderer* renderer, Object a, Object b);
SDL_Point* Collider_TransformPointsLocationToWorldLocation(Object object);

#endif