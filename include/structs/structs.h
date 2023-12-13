
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

#ifndef _STRUCTS_H_
#define _STRUCTS_H_


#define GET_VARIABLE_NAME(Variable) (#Variable)
#define NO_INPUT_VALUE 0

//test macro
#define delay(time) \
{                   \
    SDL_Delay(time);\
                    \
}      

// RGBA 
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} RGBA;

// Vector2
typedef struct {
    float x;
    float y;
} Vector2;

typedef struct
{
    Vector2 position; // World position
    Vector2 rotation; // Rotation in degrees
    Vector2 scale; // Scale
} Transform;

// Size2
typedef struct{
    float width;
    float height;
} Size2;

// Polygon
typedef struct {
    RGBA color;
    Size2 size;
    SDL_Point* points;
    int pointsCount;
    bool hasCollider;
    bool isFillIn;
} Polygone;


// Object
typedef struct
{
    Polygone* polygone; // array of polygones
    int polygonesCount; // number of polygones
    Transform transform; // transform of the object
    Size2 size; // size of the object, will affect all polygones
    bool hasCollider; // if false, all polygons will avoid "hasCollider" check
} Object;

// WorldDynamicObject
typedef struct{
    Object* object; // object
    Vector2 velocity; // velocity of the object
} WorldDynamicObject;

// RendererObject
typedef struct
{
    Object* object;
    int zIndex;
} RendererObject;

// DeltaTime
typedef struct{
    double _deltaTime;
    Uint32 _lastFrameTime;
} DeltaTime;


//////////////////////////
////// BASICSHAPES //////
//////////////////////////

typedef struct
{
    Object* object;
    Size2 size;
} BasicShapes_Rectangle;

typedef struct
{
    Object* object;
    Size2 size;
} BasicShapes_Triangle;

typedef struct
{
    Object* object;
    float radius;
} BasicShapes_Circle;

typedef struct
{


} AxisInput;

typedef struct
{

} ActionInput;


// enum type of key pressed
typedef enum{
    IPT_PRESSED,
    IPT_RELEASED,
    IPT_NONE
} InputPressedType;

typedef enum{
    IPT_AXIS,
    IPT_ACTION
} InputType;

#endif