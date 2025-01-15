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
  // Init
  SDL_Init(SDL_INIT_VIDEO);
  PrintVersion();

  // Variable Creation
  Cloudscape::Thunder::Window window("Citygloom", 900, 600);
  SDL_Renderer* renderer = SDL_CreateRenderer(window.GetSDLWindow(), NULL); // leave NULL to let SDL choose best renderer

  SDL_FRect rect;
  rect.w = 100;
  rect.h = 100;
  rect.x = 900 / 2.0f - rect.w / 2.0f;
  rect.y = 600 / 2.0f - rect.h / 2.0f;

  bool gameIsRunning = true;

  // Setup Parameters

  while (gameIsRunning)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
      {
        gameIsRunning = false;
      }

      SDL_SetRenderDrawColor(renderer, 20, 30, 30, SDL_ALPHA_OPAQUE);
      SDL_RenderClear(renderer);
      SDL_SetRenderDrawColor(renderer, 150, 0, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderFillRect(renderer, &rect);
      SDL_RenderPresent(renderer);
    }
  }

  SDL_DestroyRenderer(renderer);

  SDL_Quit();
  return 0;
}