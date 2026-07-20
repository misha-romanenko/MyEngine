#include <stdio.h>
#include "Engine.h"

#define WIDTH 480
#define HEIGHT 720

typedef struct Player {
  
  float angle;
  float jump_force;
  Rect PlayerRect;
  float velocity;
  int skin;
  
      

} Player;

typedef struct World {
  float gravity;
  

} World;

typedef struct Pipe
{
    float x;          // X position of the pipe pair
    float gapY;       // Y position of the gap (top of the hole)
    float gapHeight;  // Size of the hole

    float width;
} Pipe;

World world = {
  .gravity = 400.0f,
};

Pipe pipe[3] = {

{
    .x = 500,
    .gapY = 200,
    .gapHeight = 180,
    .width = 80
},

{
    .x = 700,
    .gapY = 200,
    .gapHeight = 180,
    .width = 80
},

{
    .x = 900,
    .gapY = 200,
    .gapHeight = 180,
    .width = 80
},
};


Player potato = {
.PlayerRect = {

.x = 100,
.y = 100,
.width = 64,
.height = 48

},
.jump_force = -150.0f,
.angle = 0.0f,
.skin = 1,

};





  




int main(void)
{
  
  
    

    if (
    EngineInit(WIDTH, HEIGHT, "moi pelle")
    ) { SDL_Log("EngineInit issue :\("); return 1; }

    

    SDL_Log("Window pointer: %p", (void *)EngineWindow);
    SDL_Log("Renderer pointer: %p", (void *)EngineRenderer);
    SDL_Log("Video driver: %s", SDL_GetCurrentVideoDriver());

    Colour BLACK = {
    0,
    0,
    0,
    255
    };
    Colour RED = {255, 0, 0, 255};
    
    Texture *Pig = LoadTexture("assets/FlappyPig.png");
    Texture *Potato = LoadTexture("assets/potato2.png");
    Texture *Pipe = LoadTexture("assets/pipe.png");

    
    

  

    while (!IsQuit())
    {
        float delta_time = GetFrameTime();

        EngineBeginFrame();
        
        // Black background
        DrawBackground(RED);

        
        

        for (int i = 0; i < 3; i++)
        {
        // move pipe
        // respawn if off screen
        // draw top and bottom rectangles

    
        pipe[i].x -= 150.0f * delta_time;

        if (pipe[i].x + pipe[i].width < 0)
        {
          pipe[i].x = WIDTH + 100;
          pipe[i].gapY = rand() % 400 + 100; // random gap position
        }

        Rect topPipe = {
          .x = pipe[i].x,
          .y = 0,
          .width = pipe[i].width,
          .height = pipe[i].gapY
        };

        Rect bottomPipe = {
          .x = pipe[i].x,
          .y = pipe[i].gapY + pipe[i].gapHeight,
          .width = pipe[i].width,
          .height = HEIGHT - (pipe[i].gapY + pipe[i].gapHeight)
        };

        DrawTextureRotated(Pipe, NULL, topPipe, 0.0, FLIP_VERTICAL);
        DrawTextureRotated(Pipe, NULL, bottomPipe, 0.0, FLIP_NONE);

        }


        potato.velocity += world.gravity * delta_time;

        if (potato.velocity > 300){
          potato.velocity = 300;
        }



        potato.PlayerRect.y += potato.velocity * delta_time;

        if( IsKeyPressed(SDL_SCANCODE_A) || 
            IsKeyPressed(SDL_SCANCODE_S) || 
            IsKeyPressed(SDL_SCANCODE_D) || 
            IsKeyPressed(SDL_SCANCODE_SPACE) ){

          potato.velocity = potato.jump_force;
          
        }
        if( IsKeyPressed(SDL_SCANCODE_1)){

          potato.skin = 1;
          
        }if( IsKeyPressed(SDL_SCANCODE_2)){

          potato.skin = 2;
          
        }



        potato.angle = potato.velocity / 6.0;

        if (potato.angle >= 360) potato.angle = 0.0;

        switch(potato.skin)
        {
          case 1:
            DrawTextureRotated(Potato, NULL, potato.PlayerRect, potato.angle, FLIP_NONE);
            break;
          case 2:
            DrawTextureRotated(Pig, NULL, potato.PlayerRect, potato.angle, FLIP_NONE);
            break;

        }

       
        
        
        
        //DrawRectangle(BLACK, (Rect){100, 100, 144, 100});

        
        EndDrawing();

        

        FPSLimitSet(180);
    }
    
    
    
    FreeTexture(Pig);
    FreeTexture(Potato);
    FreeTexture(Pipe);

    DestroyEngine();

    return 0;
}






