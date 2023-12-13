#include <game_content/player/player.h>
#include <engine/basicShapes/basicShapes.h>


Player* Player_init(float x, float y)
{
   Player* player = malloc(sizeof(Player));
   player->health = 100;
   player->x = x;
   player->y = y;
   player->physics = Player_initPhysics(player);
   player->character = Player_initCharacter(player);
   SDL_Event event;

   //object
   player->character->_object->object->transform.position = (Vector2){player->x, player->y};
   player->character->_object->object->size = (Size2){50, 50};
   player->character->_object->object->hasCollider = true;

   BasicShapes_Rectangle* rectangle = BasicShapes_InitRectangle(50, 50, (Vector2){player->x, player->y}, (RGBA){255, 0, 255, 255}, true);

   player->character->_object->object->polygone = rectangle->object->polygone;


   
   
   
   // axis
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_z,  1, Player_Input_MoveUp);
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_s,  -1, Player_Input_MoveUp);
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_q,  1, Player_Input_MoveLeft);
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_d,  -1, Player_Input_MoveLeft);

   // actions
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_SPACE, NO_INPUT_VALUE, Player_Input_MoveJumpTest);

   //test
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_UP, NO_INPUT_VALUE, Player_Input_AddZindex);
   Character_AddInput(player->character, IPT_PRESSED, IPT_AXIS, SDLK_DOWN, NO_INPUT_VALUE, Player_Input_RemoveZindex);
   


   return player;
}

Physics* Player_initPhysics(Player* player)
{
   Physics* physics = malloc(sizeof(Physics));
   physics->_canFall = true;
   physics->_isFalling = false;
   return physics;
}

Character* Player_initCharacter(Player* player)
{
   return Character_init();
}


void Player_Draw(Player* player, Renderer* renderer)
{
   // No sprite yet so we draw a rectangle
   // player with a body, a head and 2 legs

   //update polygon position
   player->character->_object->object->transform.position = (Vector2){player->x, player->y};

   Renderer_AddObjectToRender(renderer, player->character->_object->object, player->character->zIndex);


}

void Player_Input_MoveUp(void* object, int value)
{
   Player* playerPtr = (Player*)object;
   playerPtr->y -= value * (playerPtr->character->_movementComponent->maxWalkSpeed * playerPtr->deltaTime);
}

void Player_Input_MoveLeft(void* object, int value)
{
   Player* playerPtr = (Player*)object;
   playerPtr->x -= value * (playerPtr->character->_movementComponent->maxWalkSpeed * playerPtr->deltaTime);
   printf("new location : %f, %f\n", playerPtr->x, playerPtr->y);
}


void Player_Input_MoveJumpTest(void* object)
{
   printf("jump\n");
}



//testr
void Player_Input_AddZindex(void* object)
{
   Player* playerPtr = (Player*)object;

   if(playerPtr->character->zIndex > 3)
   {
      return;
   }
   playerPtr->character->zIndex++;

   printf("zindex: %d\n", playerPtr->character->zIndex);
}

void Player_Input_RemoveZindex(void* object)
{
   Player* playerPtr = (Player*)object;

   if(playerPtr->character->zIndex < -3)
   {
      return;
   }

   playerPtr->character->zIndex--;

   printf("zindex: %d\n", playerPtr->character->zIndex);
}


