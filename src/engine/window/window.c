#include "../../../include/engine/window/window.h"

#include <SDL.h>



Window* Window_Create(Size2 screenSize)
{
    #if defined(USE_VULKAN)
        #define WINDOW_TYPE SDL_WINDOW_VULKAN
    #elif defined(USE_METAL)
        #define WINDOW_TYPE SDL_WINDOW_METAL
    #elif defined(USE_OPENGL)
        #define WINDOW_TYPE SDL_WINDOW_OPENGL
    #else
        #define WINDOW_TYPE 0
    #endif



    printf("Window_init\n");
    Window* window = malloc(sizeof(Window));
    window->_screenSize = screenSize;
    window->_title = "Game";
    printf("    window type : %d", WINDOW_TYPE);
    window->_window = SDL_CreateWindow(window->_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window->_screenSize.width, window->_screenSize.height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC | WINDOW_TYPE);
    printf("    Window created");
    return window;
}


void Window_Destroy(Window* window)
{
    
}
