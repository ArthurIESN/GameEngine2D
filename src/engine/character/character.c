#include <engine/character/character.h>

Character* Character_init() {
    Character* character = malloc(sizeof(Character));

    // init default parameters for movements
    Movement* movementDefaultParameters = malloc(sizeof(Movement));
    movementDefaultParameters->gravityScale = 1;
    movementDefaultParameters->maxAcceleration = 1;
    movementDefaultParameters->crouchHalfHeight = 24;
    movementDefaultParameters->mass = 50;
    movementDefaultParameters->canCrouch = true;
    movementDefaultParameters->canJump = true;
    movementDefaultParameters->canWalk = true;
    movementDefaultParameters->canSprint = true;
    movementDefaultParameters->canFall = true;
    movementDefaultParameters->isCrouched = false;
    movementDefaultParameters->isSprinting = false;
    movementDefaultParameters->isWalking = false;
    movementDefaultParameters->isJumping = false;
    movementDefaultParameters->isFalling = false;
    movementDefaultParameters->maxWalkSpeed = 800;
    movementDefaultParameters->maxWalkSpeedCrouched = 10;
    movementDefaultParameters->jumpZVelocity = 1;
    movementDefaultParameters->airControl = 1;




    //character->_SDL_sprite = Sprite_init();
    //character->_physicsComponent = Physics_init();
    character->_movementComponent = movementDefaultParameters;
    character->_inputsComponent = Inputs_init();

    character->_object = malloc(sizeof(WorldDynamicObject));
    character->_object->object = malloc(sizeof(Object));

    character->zIndex = 0;

    
    return character;
}

void Character_AddInput(Character* character, InputPressedType inputPressedType, InputType type, SDL_Keycode key, int value, void* callbackFunction) {
    Inputs_AddEmbeddedInput(character->_inputsComponent, inputPressedType, key, type, value, callbackFunction);
}


