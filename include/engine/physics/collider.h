#ifndef COLLIDER_H
#define COLLIDER_H

#include <stdbool.h>

#include <engine/renderer/renderer.h>
#include <structs/structs.h>

#include <SDL.h>

bool Collider_checkColliders(Renderer* renderer, DynamicObject* dynamicObjects, Object* staticObjects);
bool Collider_CanCollide(Object a, Object b);
SDL_Point* Collider_TransformPointsLocationToWorldLocation(Object object);

#endif