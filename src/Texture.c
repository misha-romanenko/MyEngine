#include "Texture.h"
#include <SDL3/SDL.h>
#include <stdlib.h>



Texture *LoadTexture(const char *filepath){

  Texture *ReturnStruct = malloc(sizeof(Texture));;

  ReturnStruct->surface = IMG_Load(filepath);

  if (!ReturnStruct->surface)
  {
    SDL_Log("Omg an error with surface: %s", SDL_GetError());
  }

  ReturnStruct->texture = SDL_CreateTextureFromSurface(EngineRenderer, ReturnStruct->surface);

  return ReturnStruct;
}

bool FreeTexture(Texture *texture)
{
  SDL_DestroyTexture(texture->texture);

  SDL_DestroySurface(texture->surface);
  
  free(texture);
}



void DrawBackground(Colour colour)
{

  SDL_SetRenderDrawColor(EngineRenderer, colour.Red, colour.Green, colour.Blue, colour.Alpha);

  SDL_RenderClear(EngineRenderer);

}

void DrawTexture(Texture *TextureStruct, Rect *source, Rect destination)
{
  
  
  SDL_FRect *ptr = NULL;

  SDL_FRect DestinationCopy = GetFRectFromRect(destination);

  SDL_FRect SourceCopy;

  if (source != NULL)
  {
    SourceCopy = GetFRectFromRect(*source);
      ptr = &SourceCopy;
  }

  SDL_RenderTexture(
    EngineRenderer,
    TextureStruct->texture,
    ptr,
    &DestinationCopy);
}

void DrawTextureRotated(Texture *TextureStruct, Rect *source, Rect destination, float rotation, FlipMode flip_type)
{

  SDL_FRect *ptr = NULL;

  SDL_FRect DestinationCopy = GetFRectFromRect(destination);

  SDL_FRect SourceCopy;

  if (source != NULL)
  {
    SourceCopy = GetFRectFromRect(*source);
    ptr = &SourceCopy;
  }

  SDL_FlipMode sdlFlip;

  switch (flip_type)
  {
    case FLIP_NONE:
        sdlFlip = SDL_FLIP_NONE;
        break;

    case FLIP_HORIZONTAL:
        sdlFlip = SDL_FLIP_HORIZONTAL;
        break;

    case FLIP_VERTICAL:
        sdlFlip = SDL_FLIP_VERTICAL;
        break;
  }

  SDL_RenderTextureRotated(
    EngineRenderer,
    TextureStruct->texture,
    ptr,
    &DestinationCopy,
    rotation,
    NULL,
    sdlFlip
);
}


void DrawRectangle(Colour colour, Rect rect)
{
  SDL_SetRenderDrawColor(EngineRenderer, colour.Red, colour.Green, colour.Blue, colour.Alpha);

  SDL_FRect sdlRect = {
    rect.x,
    rect.y,
    rect.width,
    rect.height
  };

  SDL_RenderFillRect( EngineRenderer , &sdlRect);

}

void DrawOutline(Rect OutlineRect)
{

  //SDL_RenderRect(EngineRenderer, GetFRectFromRect(OutlineRect));

}


void EndDrawing(void)
{
    SDL_RenderPresent(EngineRenderer);
}


