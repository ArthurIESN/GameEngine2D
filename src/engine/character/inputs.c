#include <engine/character/inputs.h>

Inputs* Inputs_init() {
    printf("\nInputs_init\n");
    Inputs* inputs = malloc(sizeof(Inputs));

    inputs->move_up = 0;
    inputs->move_left = 0;

    inputs->jump = false;
    inputs->_callbackFunctions = malloc(sizeof(Input_CallbackFunctions));
    inputs->_callbackFunctions->numInputs = 0;

    for(int i = 0; i < MAX_INPUTS; i++)
    {
        inputs->_callbackFunctions->currentInputsPressed[i] = -1;
    }


    return inputs;
}

void Inputs_AddInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, void* callbackFunction) {
    input->_callbackFunctions->InputFunctions[input->_callbackFunctions->numInputs] = callbackFunction;
    input->_callbackFunctions->InputKeys[input->_callbackFunctions->numInputs] = key;
    input->_callbackFunctions->numInputs++;
    printf("    input type %d set at %d for callback function \n",key , input->_callbackFunctions->numInputs);
}

void Inputs_AddEmbeddedInput(Inputs* input, InputPressedType inputPressedType, SDL_Keycode key, InputType type, int value, void* callbackFunction) {
    input->_callbackFunctions->InputFunctions[input->_callbackFunctions->numInputs] = callbackFunction;
    input->_callbackFunctions->InputKeys[input->_callbackFunctions->numInputs] = key;
    input->_callbackFunctions->types[input->_callbackFunctions->numInputs] = type;
    input->_callbackFunctions->inputsPressedType[input->_callbackFunctions->numInputs] = inputPressedType;

    if(type == IPT_AXIS)
    {
        input->_callbackFunctions->values[input->_callbackFunctions->numInputs] = value;

        printf("    input (eventId : %d) value %d set at %d for callback function \n",key , input->_callbackFunctions->values[input->_callbackFunctions->numInputs], input->_callbackFunctions->numInputs);
    }
    else
    {
        printf("    input (eventId : %d) set at %d for callback function \n",key, input->_callbackFunctions->numInputs);
    }

    input->_callbackFunctions->numInputs++;
}



void Inputs_HandleEvents(Inputs* input, void* object) 
{
    for (int i = 0; i < input->_callbackFunctions->numInputs; i++)
    {
        SDL_Keycode keyEvent = input->_callbackFunctions->currentInputsPressed[i];
        for(int j = 0; j < MAX_INPUTS; j++)
        {
            if (keyEvent == input->_callbackFunctions->InputKeys[j]) 
            {
                if(input->_callbackFunctions->types[j] == IPT_AXIS)
                {
                    input->_callbackFunctions->InputFunctions[j](object, input->_callbackFunctions->values[j]);
                    break;
                }
                else
                {
                    input->_callbackFunctions->InputFunctions[j](object);
                    break;
                }
            }
        }
    }    
}


void Inputs_InputManager(Inputs* input, SDL_Event event) 
{
    switch (event.type) 
    {
        case SDL_KEYDOWN:
            if (event.key.keysym.sym != 0) 
            {
                // count current event inputs
                int currentNumberOfInputs = 0;
                while(input->_callbackFunctions->currentInputsPressed[currentNumberOfInputs] != -1)
                {
                    currentNumberOfInputs++;
                }    

                bool keyIsAlreadyAdded = false;
                for (int i = 0; i < MAX_INPUTS; i++) 
                {
                    if (input->_callbackFunctions->currentInputsPressed[i] == event.key.keysym.sym) 
                    {
                        keyIsAlreadyAdded = true;

                        if(input->_callbackFunctions->inputsPressedType[i] == IPT_ACTION)
                        {
                            input->_callbackFunctions->currentInputsPressed[i] = -1;

                            for(int j = i; j < MAX_INPUTS; j++)
                            {
                                input->_callbackFunctions->currentInputsPressed[j] = input->_callbackFunctions->currentInputsPressed[j+1];
                            }

                            input->_callbackFunctions->currentInputsPressed[MAX_INPUTS - 1] = -1;
                        }
                        break;
                    }
                }
                if (!keyIsAlreadyAdded) 
                {
                    input->_callbackFunctions->currentInputsPressed[currentNumberOfInputs] = event.key.keysym.sym;
                }
            }
            break;
        
        case SDL_KEYUP:
            for(int i = 0; i < MAX_INPUTS; i++)
            {
                if (input->_callbackFunctions->currentInputsPressed[i] == event.key.keysym.sym)
                {
                    input->_callbackFunctions->currentInputsPressed[i] = -1;

                    for(int j = i; j < MAX_INPUTS; j++)
                    {
                        input->_callbackFunctions->currentInputsPressed[j] = input->_callbackFunctions->currentInputsPressed[j+1];
                    }

                    input->_callbackFunctions->currentInputsPressed[MAX_INPUTS - 1] = -1;
                    break;
                }
            }
            break;           
    }
}
