#ifndef ENGINE_H
#define ENGINE_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdbool.h>
#include <stdlib.h>

extern SDL_Window *EngineWindow;
extern SDL_Renderer *EngineRenderer;
extern SDL_Event EngineEvent;

extern bool KeysPressed[SDL_SCANCODE_COUNT];
extern bool KeysReleased[SDL_SCANCODE_COUNT];
extern bool KeysDown[SDL_SCANCODE_COUNT];

extern bool EngineQuit;

typedef enum FlipMode
{
    FLIP_NONE,
    FLIP_HORIZONTAL,
    FLIP_VERTICAL
} FlipMode;

typedef struct Colour 
{
  int Red;
  int Green;
  int Blue;
  int Alpha;
}  Colour;

typedef struct Texture 
{
  SDL_Surface *surface;
  SDL_Texture *texture;
} Texture;

typedef struct Rect {
  float x;
  float y;
  float width;
  float height;
} Rect;

Texture *LoadTexture(const char *filepath);

void DrawTexture(Texture *TextureStruct, Rect *source, Rect destination);

void DrawTextureRotated(Texture *TextureStruct, Rect *source, Rect destination, float rotation, FlipMode flip_type);

void DrawRectangle(Colour colour, Rect rect);

int EngineInit(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char *WINDOW_LABLE);

void DrawBackground(Colour colour);

void FPSLimitSet(int fps_limit_value);

SDL_FRect GetFRectFromRect(Rect OriginalRect);

void EndDrawing(void);

bool IsKeyDown(SDL_Scancode key);

bool IsKeyPressed(SDL_Scancode key);

bool IsKeyReleased(SDL_Scancode key);

float GetFrameTime(void);

bool IsQuit(void);

void EngineBeginFrame(void);

bool FreeTexture(Texture *texture);

void EngineDestroy();


#endif // !ENGINE_H
