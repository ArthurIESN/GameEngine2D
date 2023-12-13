#include <engine/physics/collider.h>

bool Collider_checkCollision(Renderer* renderer, Object a, Object b)
{
    bool cannotCollide =    a.polygone == NULL || a.polygone->points == NULL || a.polygone->pointsCount < 3 || 
                            b.polygone == NULL || b.polygone->points == NULL || b.polygone->pointsCount < 3 ||
                            !a.hasCollider || !b.hasCollider;

    if(!cannotCollide)
    {
        printf("Collider : cannot check collision\n");
        return false;
    }
    //TODO



}

SDL_Point* Collider_TransformPointsLocationToWorldLocation(Object object)
{

    SDL_Point* points = malloc(sizeof(SDL_Point) * object.polygone->pointsCount);


   

    return points;
}

