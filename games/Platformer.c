
#include "Engine.h"

#define WIDTH 1080
#define HEIGHT 720

int main ()
{

EngineInit(WIDTH, HEIGHT, "Haista pissa");

Texture *BlobTexture = LoadTexture("assets/GreenBlobIdle.png");

Animation BlobIdleAnimation = {

  .cur = 1,
  .first = 0,
  .last = 1,

  .FrameWidth = 128,
  .FrameHeight = 128,

  .FramesPerRow = 2,

  .AnimationSpeed = 1,
  .duration_left = 0.0,

};

Rect BlobRect = { .x = 100, .y = 100,
                  .width = 128, .height = 128
                };

while (!IsQuit())
{
  EngineBeginFrame();

  float delta_time = GetFrameTime();


  if (IsKeyDown(SDL_SCANCODE_W)) {

     

  }







  AnimationUpdate(&BlobIdleAnimation, delta_time);

  Rect BlobIdleFrame = AnimationFrame(&BlobIdleAnimation);

  DrawBackground((Colour){255,155,155,255});

  DrawTexture(BlobTexture, &BlobIdleFrame, BlobRect);




  EndDrawing();

}

EngineDestroy();

return 0;
}

