#include <Engine.h>

#define WIDTH 720
#define HEIGHT 480


int main ()
{

EngineInit(WIDTH, HEIGHT, "haista sissa");

Animation BlobAnim = {

  .cur = 1,
  .first = 0,
  .last = 1,
  .FrameWidth = 128,
  .FrameHeight = 128,

  .FramesPerRow = 2,

  .AnimationSpeed = 1,
  .duration_left = 0.0,

};


Texture *BlobTexture = LoadTexture("assets/GreenBlobIdle.png");

 float rotation = 0;

 SDL_FPoint point1 = {
  .x = 100,
  .y = 100

 };

while (!IsQuit())
{

  EngineBeginFrame();

  float delta_time = GetFrameTime();

  AnimationUpdate(&BlobAnim, delta_time);

  Rect PlayerAnimRect = AnimationFrame(&BlobAnim);

  rotation += 20 * delta_time;
  if (point1.x > 0)
    point1.x += 20 * delta_time;
  if (point1.x > 400)
    point1.x -= 20 * delta_time;

  DrawBackground((Colour){255, 123, 32, 255});
  DrawTextureRotatedPro(BlobTexture, &PlayerAnimRect, (Rect){100, 100, 128, 128}, rotation, FLIP_NONE, &point1);

  EndDrawing();
  
  }
}
