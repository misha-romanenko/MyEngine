#ifndef INPUT_H
#define INPUT_H

#include <SDL3/SDL.h>
#include <stdbool.h>

extern bool KeysPressed[SDL_SCANCODE_COUNT];
extern bool KeysReleased[SDL_SCANCODE_COUNT];
extern bool KeysDown[SDL_SCANCODE_COUNT];

bool IsKeyDown(SDL_Scancode key);

bool IsKeyPressed(SDL_Scancode key);

bool IsKeyReleased(SDL_Scancode key);

#endif
