#include <Engine.h>

#define WIDTH 720
#define HEIGHT 480



int main ()
{

EngineInit(WIDTH, HEIGHT, "haista sissa");

Animation BlobAnim = {

  .cur = 1,
  .first = 1,
  .last = 2,
  .FrameWidth = 128,
  .FrameHeight = 128,

  .FramesPerRow = 2

  .animSpeed = 1.0f,
  .duration_left = 0.0,



};


Texture *BlobTexture = LoadTexture("assets/GreenBlobIdle.png");




while (!IsQuit())
{
  EngineBeginFrame();

  float delta_time = GetFrameTime();

  AnimationUpdate(&BlobAnim, delta_time);

  DrawBackground((Colour){255, 123, 32, 255});
  DrawTexture(BlobTexture, AnimationFrame(&BlobAnim), (Rect){100, 100, 128, 128});

  EndDrawing();
  
}





}
