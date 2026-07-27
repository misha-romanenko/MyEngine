#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL3_image/SDL_image.h>
#include "Shapes.h"
#include "Event.h"

typedef struct Texture 
{

  SDL_Surface *surface;
  SDL_Texture *texture;

} Texture;

typedef struct Colour 
{

  int Red;
  int Green;
  int Blue;
  int Alpha;
  
}  Colour;

typedef struct Animation {

  
  
  int first;
  int last;
  int cur;

  float animSpeed;
  float duration_left;

  int FramesPerRow;
  int FrameWidth;
  int FrameHeight;

} Animation;

typedef enum FlipMode
{
    FLIP_NONE,
    FLIP_HORIZONTAL,
    FLIP_VERTICAL

} FlipMode;


Texture *LoadTexture(const char *filepath);

void DrawBackground(Colour colour);



void DrawTexture(Texture *TextureStruct, Rect *source, Rect destination);

void DrawTextureRotated(Texture *TextureStruct, Rect *source, Rect destination, float rotation, FlipMode flip_type);


void AnimationUpdate(Animation *self, float delta_time);

Rect *AnimationFrame(Animation *self);


void DrawRectangle(Colour colour, Rect rect);

void DrawOutline(Rect OutlineRect);

bool FreeTexture(Texture *texture);

void EndDrawing(void);




#endif
