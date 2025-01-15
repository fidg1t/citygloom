#include <SDL3/SDL.h>
#include <iostream>
#include "version.h"
#include <window.h>

static void PrintVersion()
{
  std::string version = std::to_string(CITYGLOOM_VERSION_MAJOR) + "." + std::to_string(CITYGLOOM_VERSION_MINOR) + "."
    + std::to_string(CITYGLOOM_VERSION_PATCH) + "." + std::to_string(CITYGLOOM_VERSION_TWEAK);
}

int main(void)
{
  SDL_Init(SDL_INIT_VIDEO);

  Cloudscape::Thunder::Window window("Citygloom", 900, 600);

  PrintVersion();

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

  SDL_Quit();
  return 0;
}