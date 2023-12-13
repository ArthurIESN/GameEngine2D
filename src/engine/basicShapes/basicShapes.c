#include <engine/basicShapes/basicShapes.h>


BasicShapes_Rectangle* BasicShapes_InitRectangle(float height, float width, Vector2 position, RGBA color, bool hasCollider)
{
    BasicShapes_Rectangle* rectangle                    = malloc(sizeof(BasicShapes_Rectangle));
    rectangle->size.height                              = height;
    rectangle->size.width                               = width;
    rectangle->object                                   = malloc(sizeof(Object));
    rectangle->object->polygone                         = malloc(sizeof(Polygone));
    rectangle->object->polygone->pointsCount            = 4;

    SDL_Point* points                                   = malloc(sizeof(SDL_Point) * rectangle->object->polygone->pointsCount);
    points[0]                                           = (SDL_Point){0, 0};
    points[1]                                           = (SDL_Point){rectangle->size.width, 0};
    points[2]                                           = (SDL_Point){rectangle->size.width, rectangle->size.height};
    points[3]                                           = (SDL_Point){0, rectangle->size.height};

    rectangle->object->polygone->points                 = points;
    rectangle->object->polygone->color                  = color;
    rectangle->object->transform.position               = position;
    rectangle->object->size                             = rectangle->size;
    rectangle->object->hasCollider                      = hasCollider;
    rectangle->object->polygone->isFillIn               = true;

    return rectangle;
}

void BasicShapes_InitTriangle(BasicShapes_Triangle* triangle)
{

}

BasicShapes_Circle* BasicShapes_InitCircle(float radius, int numberOfPoints, Vector2 position, RGBA color, bool hasCollider)
{
    BasicShapes_Circle* circle                          = malloc(sizeof(BasicShapes_Circle));
    circle->radius                                      = radius;
    circle->object                                      = malloc(sizeof(Object));
    circle->object->polygone                            = malloc(sizeof(Polygone));
    circle->object->polygone->color                     = color;
    circle->object->transform.position                  = position;
    circle->object->hasCollider                         = hasCollider;
    circle->object->polygone->isFillIn                  = true;

    //calculate coordonates of each points
    circle->object->polygone->pointsCount               = numberOfPoints;
    SDL_Point* points                                   = malloc(sizeof(SDL_Point) * circle->object->polygone->pointsCount);
    points[0]                                           = (SDL_Point){radius + position.x, position.y};

    for(int i = 1; i < circle->object->polygone->pointsCount; i++)
    {
        points[i] = (SDL_Point){(int)(radius * cos(i * 2 * M_PI / circle->object->polygone->pointsCount) + position.x), (int)(radius * sin(i * 2 * M_PI / circle->object->polygone->pointsCount) + position.y)};
    }
    circle->object->polygone->points                    = points;

    return circle;
}

void BasicShapes_DrawRectangle(BasicShapes_Rectangle* rectangle, Renderer* renderer)
{
    Renderer_DrawPolygon(renderer, true, *rectangle->object);
}
