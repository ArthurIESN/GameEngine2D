#pragma once

#ifndef PLAYER_H
#define PLAYER_H


#include <stdint.h>


#include <SDL.h>

#include <engine/physics/physics.h>
#include <engine/renderer/renderer.h>
#include <engine/renderer/gameState.h>
#include <engine/character/character.h>
#include <structs/structs.h>

typedef struct{
    uint8_t health;
    float x;
    float y;
    double deltaTime;
    Physics* physics;
    Character* character;
    BasicShapes_Circle* circle;
} Player;

Player* Player_init(float x, float y);
Physics* Player_initPhysics(Player* player);
Character* Player_initCharacter(Player* player);


void Player_Draw(Player* player, Renderer* renderer);

// player inputs

void Player_Input_MoveUp(void* object, int value);
void Player_Input_MoveLeft(void* object, int value);

void Player_Input_MoveJumpTest(void* object);

//test
void Player_Input_AddZindex(void* object);
void Player_Input_RemoveZindex(void* object);






#endif