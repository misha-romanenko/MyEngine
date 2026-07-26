
#include <Engine.h>

#define WIDTH 1080
#define HEIGHT 720

typedef struct Player {

  float jump_force;
  Rect PlayerRect;

  float velocityY;
  float dx;

  bool IsOnGround;

  bool LookinRight;

  float skolz;

  float speed;
  
} Player;


int main ()
{


EngineInit(WIDTH, HEIGHT, "Haista pissa");

Player Dude = {

.PlayerRect = {
    .x = 100,
    .y = 300,
    .width = 48,
    .height = 64
  },

.jump_force = 100.0f,
.velocityY = 0.0f,
.skolz = 0.0f

};

Rect Floor = {
  .x = 0,
  .y = HEIGHT - 32,
  .width = WIDTH,
  .height = 32
};

Rect Box = {
  .x = WIDTH - 240,
  .y = HEIGHT - 64,
  .width = 48,
  .height = 64,


};

float gravity = 150.0f;

Dude.speed = 150.0f;

while (!IsQuit())
{
  EngineBeginFrame();

  float delta_time = GetFrameTime();

  if (IsKeyDown(SDL_SCANCODE_D))
  {
    if ( Dude.skolz < 200  )
      Dude.skolz += 100 * delta_time;


   
  }
  if (IsKeyDown(SDL_SCANCODE_A))
  {
    if ( Dude.skolz > -200  )
      Dude.skolz -= 100 * delta_time;
  }

  Dude.dx = Dude.skolz;
  Dude.PlayerRect.x += Dude.dx * delta_time;

  if (IsCollision(Dude.PlayerRect, Box))
  {
    if (Dude.dx > 0)
      Dude.PlayerRect.x = Box.x - Dude.PlayerRect.width;
    if (Dude.dx < 0)
      Dude.PlayerRect.x = Box.x + Dude.PlayerRect.width;

  }



  Dude.velocityY += gravity * delta_time;

  if (IsKeyPressed(SDL_SCANCODE_SPACE) && Dude.IsOnGround) {
    Dude.velocityY = -100;
  }
  
  Dude.PlayerRect.y += Dude.velocityY * delta_time;


  if (IsCollision(Dude.PlayerRect, Floor))
  {
    
    Dude.PlayerRect.y = Floor.y - Dude.PlayerRect.height;
    Dude.velocityY = 0;

    Dude.IsOnGround = true;

  }

  


  

  
    
  DrawBackground((Colour){255,155,155,255});

  DrawRectangle((Colour){32, 223, 123, 155}, Floor);

  DrawRectangle((Colour){0, 123, 223, 155}, Dude.PlayerRect);

  DrawRectangle((Colour){255,12,12, 200}, Box);

   

  EndDrawing();

}


EngineDestroy();
return 0;
}

