#include <engine/game.h>

Game* Game_New(Size2 screenSize, float targetedFps)
{
    Game* game = malloc(sizeof(Game));
    game->_renderer = Renderer_Create(screenSize);
    game->_event = (SDL_Event){0};
    game->_isRunning = true;

    game->_targetedFps = targetedFps;

    return game;
}

void Game_UpdateDeltaTime(Game* game){
    Uint32 currentTime = SDL_GetTicks();
    game->_deltaTime._deltaTime = Game_CalculateDeltaTime(game, currentTime);
}

double Game_CalculateDeltaTime(Game* game, Uint32 currentTime){
    double deltaTime = (currentTime - game->_deltaTime._lastFrameTime) / 1000.0f;
    game->_deltaTime._lastFrameTime = currentTime;
    return deltaTime;
}


void Game_Pause(Game* game, bool pause){
    game->_isPaused = pause;
}

void Game_CheckColliders(Game* game)
{
    /*OLD
    // All dynamic objects will check collision with all static objects
    for(int i = 0; i < game->_world->dynamicObjectsCount; i++)
    {
        for(int j = 0; j < game->_world->staticObjectsCount; j++)
        {
            printf("objectA position : %f, %f\nObjectB position : %f, %f\n", game->_world->dynamicObjects[i].object->transform.position.x, game->_world->dynamicObjects[i].object->transform.position.y, game->_world->staticObjects[j].transform.position.x, game->_world->staticObjects[j].transform.position.y);
            bool isCollide = Collider_checkCollision(game->_renderer, *game->_world->dynamicObjects[i].object, game->_world->staticObjects[j]);
            printf("Object has %s\n", isCollide ? "collided" : "not collided");
        }
    }
    */

}