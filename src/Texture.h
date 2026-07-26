#ifndef TEXTURE_H
#define TEXTURE_H

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


#endif
