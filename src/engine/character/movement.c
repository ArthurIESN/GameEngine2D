#include <engine/character/movement.h>

#include <SDL.h>

Movement* Movement_init(float gravityScale, float maxAcceleration, 
float crouchHalfHeight, float mass, bool canCrouch, bool canJump, 
bool canWalk, bool canSprint, bool canFall, float maxWalkSpeed, 
float maxWalkSpeedCrouched, float jumpZVelocity, float airControl) 
{
    Movement* movement = malloc(sizeof(Movement));

    movement->gravityScale = gravityScale;
    movement->maxAcceleration = maxAcceleration;
    movement->crouchHalfHeight = crouchHalfHeight;
    movement->mass = mass;

    movement->canCrouch = canCrouch;
    movement->canJump = canJump;
    movement->canWalk = canWalk;
    movement->canSprint = canSprint;
    movement->canFall = canFall;

    movement->isCrouched = false;
    movement->isSprinting = false;
    movement->isWalking = false;
    movement->isJumping = false;
    movement->isFalling = false;

    // walking parameters
    movement->maxWalkSpeed = maxWalkSpeed;
    movement->maxWalkSpeedCrouched = maxWalkSpeedCrouched;

    // jumping parameters
    movement->jumpZVelocity = jumpZVelocity;
    movement->airControl = airControl;

    return movement;
}


Movement* Mouvement_SetSprint(Movement* movement, float speed, bool isSprinting) {
    movement->isSprinting = isSprinting;
    movement->maxWalkSpeed = speed;
    return movement;
}