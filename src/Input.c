#include "Input.h"

bool KeysPressed[SDL_SCANCODE_COUNT];
bool KeysReleased[SDL_SCANCODE_COUNT];
bool KeysDown[SDL_SCANCODE_COUNT];

bool IsKeyDown(SDL_Scancode key)
{
    return SDL_GetKeyboardState(NULL)[key];
}

bool IsKeyPressed(SDL_Scancode key)
{
    return KeysPressed[key];
}

bool IsKeyReleased(SDL_Scancode key)
{
  return KeysReleased[key];
}

