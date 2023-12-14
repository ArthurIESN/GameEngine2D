#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include <stdbool.h>

#include <engine/renderer/renderer.h>
#include <engine/physics/collider.h>
#include <engine/world/world.h>
#include <structs/structs.h>




typedef struct{
    Renderer* _renderer;
    SDL_Event _event;
    bool _isRunning;
    bool _isPaused;
    float _targetedFps;
    DeltaTime _deltaTime;
    World* _world;
} Game;

Game* Game_New(Size2 screenSize, float targetedFps);

void Game_UpdateDeltaTime(Game* game);
double Game_CalculateDeltaTime(Game* game, Uint32 currentTime);
void Game_Pause(Game* game, bool pause);

//game objects collider
void Game_CheckColliders(Game* game);



#endif // GAME_H
