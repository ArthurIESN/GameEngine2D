#include <stdio.h>
#include <stdbool.h>

// SDL2
#include <SDL.h>


// Engine
#include <engine/renderer/renderer.h>
#include <engine/renderer/gameState.h>
#include <engine/game.h>
#include <engine/basicShapes/basicShapes.h>

// Structs
#include <structs/structs.h>


// game content
#include <game_content/player/player.h>
#include <game_content/platform/platform.h>

//test final 2

int main(void) {
    #ifdef DEBUG
        char FPStext[32];
        float FPS_counter;
        float FPS_counter_time = 50;
    #endif
    
    Platform* platform = Platform_init();
    Player* player = Player_init(300, 300);

    Size2 screenSize = {800, 600};
    Game* game = Game_New(screenSize, 120);

    // needs to be in game content
    game->_world = World_init();

 



    Object* staticObject1 = malloc(sizeof(Object));
    staticObject1->transform.position = (Vector2){100, 100};
    staticObject1->polygone = malloc(sizeof(Polygone));
    staticObject1->polygone->pointsCount = 4;
    staticObject1->polygone->points = malloc(sizeof(SDL_Point) * staticObject1->polygone->pointsCount);
    staticObject1->polygone->points[0] = (SDL_Point){0, 0};
    staticObject1->polygone->points[1] = (SDL_Point){50, 0};
    staticObject1->polygone->points[2] = (SDL_Point){50, 50};
    staticObject1->polygone->points[3] = (SDL_Point){0, 50};
    staticObject1->polygone->color = (RGBA){255, 255, 255, 255};
    staticObject1->polygone->size = (Size2){50, 50};

    Object* staticObject2 = malloc(sizeof(Object));
    staticObject2->transform.position = (Vector2){200, 200};

    Object* staticObject3 = malloc(sizeof(Object));
    staticObject3->transform.position = (Vector2){300, 300};




    World_AddStaticObject(game->_world, staticObject1);
    World_AddDynamicObject(game->_world, player->character->_object);

    int frameRandomColorCount = 0;
    RGBA colorCircle = (RGBA){rand() % 255, rand() % 255, rand() % 255, 255};
    // print all static objects positions
    for(int i = 0; i < game->_world->WorldObjects->staticObjectsCount; i++)
    {
        printf("static object %d position: %f, %f\n", i, game->_world->WorldObjects->staticObjects[i].object->transform.position.x, game->_world->WorldObjects->staticObjects[i].object->transform.position.y);
    }

    //World_RemoveStaticObject(game->_world, 1);

    printf("--------------------\n\n");

    for(int i = 0; i < game->_world->WorldObjects->staticObjectsCount; i++)
    {
        printf("static object %d position: %f, %f\n", i, game->_world->WorldObjects->staticObjects[i].object->transform.position.x, game->_world->WorldObjects->staticObjects[i].object->transform.position.y);
    }

    // platform test 

    SDL_Point points[7] = {
        {100, 100},
        {200, 630},
        {200, 200},
        {300, 200},
        {300, 300},
        {100, 300},
        {0, 0}
    };
    int pointsCount = sizeof(points) / sizeof(points[0]);
    Platform_initPoints(platform, points, pointsCount);


    BasicShapes_Rectangle* rectangle;
    rectangle = BasicShapes_InitRectangle(500, 90, (Vector2){100, 100}, (RGBA){255, 89, 0, 255}, true);

    BasicShapes_Circle* circle;
    circle = BasicShapes_InitCircle(50, 4, (Vector2){200, 200}, (RGBA){0, 255, 0, 255}, true);
    
    player->circle = circle;

    SDL_ShowCursor(1);
    
    while (game->_isRunning) 
    {
        Game_UpdateDeltaTime(game);
        Game_CheckColliders(game);

        if(game->_isPaused)
        {
            player->deltaTime = 0;
        }
        else
        {
            player->deltaTime = game->_deltaTime._deltaTime;
        }
        

        
        while (SDL_PollEvent(&game->_event) != 0) 
        { 
            int currentNumberOfInputs = 0;
            while(player->character->_inputsComponent->_callbackFunctions->currentInputsPressed[currentNumberOfInputs] != -1)
            {
                currentNumberOfInputs++;
            }
            
            switch (game->_event.type) 
            {
                case SDL_QUIT:
                    game->_isRunning = false;
                    break;

            }
            Inputs_InputManager(player->character->_inputsComponent, game->_event);
            
        }
        

        #ifdef DEBUG
            if(FPS_counter_time >= 20)
            {
                sprintf(FPStext, "FPS: %0.2f", (1.0 / game->_deltaTime._deltaTime));
                FPS_counter_time = 0;
            }
            else
            {
                FPS_counter_time++;
            }
            SDL_SetWindowTitle(game->_renderer->window->_window, FPStext);

        #endif


        Inputs_HandleEvents(player->character->_inputsComponent, player);

        RGBA color = {30, 100, 128, 150};
        Renderer_DrawBackground(game->_renderer, color);

        //Platform_Draw(platform, game->_renderer); 
        Renderer_AddObjectToRender(game->_renderer, platform->rectangle->object, 0);
        
        Player_Draw(player, game->_renderer);

        //BasicShapes_DrawRectangle(rectangle, game->_renderer);
        Renderer_AddObjectToRender(game->_renderer, rectangle->object, 0);

        //Renderer_DrawPolygon(game->_renderer, true, *player->circle->object);
        Renderer_AddObjectToRender(game->_renderer, player->circle->object, -1);



        
        
        Renderer_Render(game->_renderer);
        SDL_Delay(1000/ (game->_targetedFps + game->_targetedFps));
    }

    SDL_DestroyWindow(game->_renderer->window->_window);
    SDL_Quit();
    
    return 0;
}
