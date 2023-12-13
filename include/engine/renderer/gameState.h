#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SDL.h>

static Uint32 SDL_tick;
static float deltaTime;



void GameState_CalculateDeltaTime();
float GameState_GetDeltaTime();
void GameState_SetSDLTick(Uint32 tick);

#endif // GAME_STATE_H






