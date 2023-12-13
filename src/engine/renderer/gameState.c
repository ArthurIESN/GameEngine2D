#include <engine/renderer/gameState.h>




void GameState_CalculateDeltaTime() {
    Uint32 newTick = SDL_GetTicks();
    float newDeltaTime = (newTick - SDL_tick) / 1000.0f;
    SDL_tick = newTick;
    deltaTime = newDeltaTime;

    printf("calculated deltaTime: %f\n", deltaTime);
}

float GameState_GetDeltaTime() {
    printf("returning deltaTime: %f\n", deltaTime);
    return deltaTime;
}

void GameState_SetSDLTick(Uint32 tick) {
    SDL_tick = tick;
}