#ifndef CHARACTER_H
#define CHARACTER_H

#include <engine/physics/physics.h>
#include <engine/character/movement.h>
#include <engine/character/inputs.h>


#include <SDL.h>

typedef struct Character Character;

struct Character{
    SDL_Surface* _SDL_sprite;
    Physics* _physicsComponent;
    Movement* _movementComponent;
    Inputs* _inputsComponent;
    WorldDynamicObject* _object;
    int zIndex;
} ;

Character* Character_init();

/*
@brief Add an input to the character inputs component. When the key is pressed, the callback component is called and execute related function
@param character The character to add the input to
@param inputPressedType The type of input to add (pressed, released, etc...)
@param type The type of input axis or action
@param key The key to bind the input to
@param value The value of the input (for axis inputs)
@param callbackFunction The function to call when the input is pressed
*/
void Character_AddInput(Character* character, InputPressedType inputPressedType, InputType type, SDL_Keycode key, int value, void* callbackFunction);


#endif // CHARACTER_H

