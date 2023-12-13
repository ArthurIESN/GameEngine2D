#ifndef _BASICSHAPES_H_
#define _BASICSHAPES_H_

#include <structs/structs.h>
#include <engine/renderer/renderer.h>

BasicShapes_Rectangle* BasicShapes_InitRectangle(float height, float width, Vector2 position, RGBA color, bool hasCollider);
void BasicShapes_InitTriangle(BasicShapes_Triangle *triangle);
BasicShapes_Circle* BasicShapes_InitCircle(float radius, int numberOfPoints, Vector2 position, RGBA color, bool hasCollider);

void BasicShapes_DrawRectangle(BasicShapes_Rectangle* rectangle, Renderer *renderer);

#endif // _BASICSHAPES_H_

