#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <structs/structs.h>

typedef struct {
    SDL_Window* _window;
    Size2 _screenSize;
    char* _title;
} Window;

Window* Window_Create(Size2 screenSize);
void Window_Destroy(Window* window);

float Window_CalculateFps(Window* window, Uint32 startTime, Uint32 endTime, int frames);

#endif