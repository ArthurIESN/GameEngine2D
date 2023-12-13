#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL.h>
#include <stdbool.h>
#include <structs/structs.h>

/*
@brief The Physics struct contains all the physics data of the game.
@param _canFall If true, the character can fall
@param _isFalling If true, the character is falling
@param _isJumping If true, the character is jumping
@param _polygones The polygones of the game
*/
typedef struct {
    bool _canFall;
    bool _isFalling;
    bool _isJumping;
    Polygone* _polygones;
} Physics;

Physics* Physics_init();

bool Physics_CheckCollision(Polygone polygone1, Polygone polygone2);

#endif
