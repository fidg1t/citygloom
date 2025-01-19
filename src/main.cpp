#include <SDL3/SDL.h>
#include <iostream>
#include "version.h"
#include <window.h>
#include <glad/glad.h>

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
  SDL_GLContext glContext = SDL_GL_CreateContext(window.GetSDLWindow());

  gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

  SDL_GL_MakeCurrent(window.GetSDLWindow(), glContext);

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

      glClearColor(.5f, .0f, .6f, 1.f);
      glGetError();
      glClear(GL_COLOR_BUFFER_BIT);
      SDL_GL_SwapWindow(window.GetSDLWindow());
    }
  }

  SDL_GL_DestroyContext(glContext);

  SDL_Quit();
  return 0;
}