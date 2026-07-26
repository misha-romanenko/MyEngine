#ifndef SHAPES_H
#define SHAPES_H

#include <SDL3/SDL.h>

typedef struct Vector
{

  float x;
  float y;

} Vector;

typedef struct Rect {
  float x;
  float y;
  float width;
  float height;
} Rect;

SDL_FRect GetFRectFromRect(Rect OriginalRect);

#endif
