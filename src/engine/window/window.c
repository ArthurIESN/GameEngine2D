#include "../../../include/engine/window/window.h"

#include <SDL.h>

Window* Window_Create(Size2 screenSize)
{
    printf("Window_Create\n");
    Window* window = malloc(sizeof(Window));
    window->_screenSize = screenSize;
    window->_title = "Game";
    window->_window = SDL_CreateWindow(window->_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window->_screenSize.width, window->_screenSize.height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC);
    return window;
}


void Window_Destroy(Window* window)
{
    
}
