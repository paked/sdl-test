#include <iostream>

#include <SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(void) {
  std::cout << "hello sdl" << std::endl;

  SDL_Window* window = NULL;
  SDL_Surface* screen = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "could not init sdl" << std::endl;

    return -1;
  }

  window = SDL_CreateWindow(
    "Hello SDL",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if (window == NULL) {
    std::cout << "could not create window" << std::endl;

    return -1;
  }

  screen = SDL_GetWindowSurface(window);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 114, 202, 232));
  SDL_UpdateWindowSurface(window);
  SDL_Delay(2000);
  SDL_DestroyWindow(window);
  SDL_Quit();

  std::cout << "goodbye world!" << std::endl;
  return 0;
}
