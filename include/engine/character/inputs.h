#ifndef INPUTS_H
#define INPUTS_H

#include <stdint.h>
#include <stdbool.h>

#include <SDL.h>

#include <structs/structs.h>


typedef void (*Input_Function)();

#define MAX_INPUTS 10


typedef struct{
    Input_Function InputFunctions[MAX_INPUTS];
    SDL_Keycode InputKeys[MAX_INPUTS];
    InputType types[MAX_INPUTS];
    InputPressedType inputsPressedType[MAX_INPUTS];
    int values[MAX_INPUTS];

    int numInputs;
    SDL_Keycode currentInputsPressed[MAX_INPUTS];

} Input_CallbackFunctions;

typedef struct {

    Input_CallbackFunctions* _callbackFunctions;

    // axis
    signed char move_up;
    signed char move_left;

    // actions
    bool jump;
} Inputs;




Inputs* Inputs_init();
void Inputs_AddInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, void* callbackFunction);
void Inputs_AddEmbeddedInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, InputType type, int value, void* callbackFunction);
void Inputs_AddAxisInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, int value, void* callbackFunction);
void Inputs_AddActionInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, void* callbackFunction);

/*
    /@brief handle all inputs events and call the callback functions
    /@param input the input component of the controlable object
    /@param object that will be passed to call the callback functions
*/
void Inputs_HandleEvents(Inputs* input, void* object);

void Inputs_InputManager(Inputs* input, SDL_Event event);

#endif // INPUTS_H









