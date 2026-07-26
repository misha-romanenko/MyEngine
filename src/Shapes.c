#include <Shapes.h>


SDL_FRect GetFRectFromRect(Rect OriginalRect){
  
  

  SDL_FRect CopyFRect = {
    .x = OriginalRect.x,
    .y = OriginalRect.y,
    .w = OriginalRect.width,
    .h = OriginalRect.height
  };

  return CopyFRect;
}

