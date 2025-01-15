#include <iostream>
#include <SDL3/SDL.h>

int main(void)
{
  SDL_InitFlags flags = SDL_INIT_VIDEO;
  SDL_Init(flags);
  
  std::cout << "Hello, Citygloom!\n";
  
  SDL_Quit();
  return 0;
}