#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <stdbool.h>

typedef struct{
    float gravityScale;
    float maxAcceleration;
    float crouchHalfHeight;
    float mass;

    bool canCrouch;
    bool canJump;
    bool canWalk;
    bool canSprint;
    bool canFall;

    bool isCrouched;
    bool isSprinting;
    bool isWalking;
    bool isJumping;
    bool isFalling;

    // walking parameters
    float maxWalkSpeed;
    float maxWalkSpeedCrouched;

    // jumping parameters
    float jumpZVelocity;
    float airControl;

    
} Movement;

Movement* Movement_init(float gravityScale, float maxAcceleration, float crouchHalfHeight, float mass, bool canCrouch, bool canJump, bool canWalk, bool canSprint, bool canFall, float maxWalkSpeed, float maxWalkSpeedCrouched, float jumpZVelocity, float airControl);

/**
 * Set sprint value 
 *
 * @param mouvement Movement component
 * @param speed New max speed value for the movement component
 * @param isSprinting New state of the sprinting
 * @return New movement component
 */
Movement* Mouvement_SetSprint(Movement* movement, float speed, bool isSprinting);

Movement* Mouvement_SetCrouch(Movement* movement, bool isCrouched);





#endif // MOVEMENT_H