#include <engine/physics/collider.h>

bool Collider_checkColliders(Renderer* renderer, DynamicObject* dynamicObjects, Object* staticObjects)
{
    // All dynamic objects will check collision with all static objects
   /* for(int i = 0; i < game->_world->; i++)
    {
        Object a = *game->_world->dynamicObjects[i].object;

        for(int j = 0; j < game->_world->staticObjectsCount; j++)
        {
            Object b = game->_world->staticObjects[j];
            bool canCollide = Collider_CanCollide(a, b);
        }
    }

    */






}

bool Collider_CanCollide(Object a, Object b)
{
    bool cannotCollide =    a.polygone == NULL || a.polygone->points == NULL || a.polygone->pointsCount < 3 || 
                            b.polygone == NULL || b.polygone->points == NULL || b.polygone->pointsCount < 3 ||
                            !a.hasCollider || !b.hasCollider;

    return !cannotCollide;
}

SDL_Point* Collider_TransformPointsLocationToWorldLocation(Object object)
{

    SDL_Point* points = malloc(sizeof(SDL_Point) * object.polygone->pointsCount);


   

    return points;
}

