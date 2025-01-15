#include <iostream>
#include "version.h"
#include <SDL3/SDL.h>
#include <string>

int main(void)
{
  SDL_InitFlags flags = SDL_INIT_VIDEO;
  SDL_Init(flags);
  
  std::string version = std::to_string(CITYGLOOM_VERSION_MAJOR) + "." + std::to_string(CITYGLOOM_VERSION_MINOR) + "."
    + std::to_string(CITYGLOOM_VERSION_PATCH) + "." + std::to_string(CITYGLOOM_VERSION_TWEAK);

  SDL_WindowFlags wFlags = 0;
  SDL_Window* window = SDL_CreateWindow("Citygloom", 900, 600, wFlags);

  bool gameIsRunning = true;

  while (gameIsRunning)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
      {
        gameIsRunning = false;
      }
    }
  }

  SDL_DestroyWindow(window);

  SDL_Quit();
  return 0;
}