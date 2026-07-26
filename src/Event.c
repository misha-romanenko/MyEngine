#include "Event.h"



SDL_Event EngineEvent;

bool EngineQuit = false;

int EngineInit(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char *WINDOW_LABLE)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
      SDL_Log("SDL_Init Error");
      return 1;
    }
    EngineWindow = SDL_CreateWindow(
        WINDOW_LABLE,       
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE);
    if (!EngineWindow)
    {
        SDL_Log("Window Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    EngineRenderer = SDL_CreateRenderer(EngineWindow, NULL);
    if (!EngineRenderer)
    {
        SDL_Log("Renderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(EngineWindow);
        SDL_Quit();
        return 1;
    }
    return 0;
}

void EngineDestroy()
{
  SDL_DestroyWindow(EngineWindow);
  SDL_DestroyRenderer(EngineRenderer);
  SDL_Quit();
}

void FPSLimitSet(int fps_limit_value)
{
  int devided_fps_limit_value = 1000.0 / fps_limit_value;
  SDL_Delay((int)devided_fps_limit_value);
}


float GetFrameTime(void) {
    static Uint64 last_counter = 0;
    static Uint64 frequency = 0;
    
    
    if (frequency == 0) {
        last_counter = SDL_GetPerformanceCounter();
        frequency = SDL_GetPerformanceFrequency();
        return 0.0f; 
    }

    Uint64 current_counter = SDL_GetPerformanceCounter();
    float delta_time = (float)(current_counter - last_counter) / (float)frequency;
    last_counter = current_counter;

    
    if (delta_time > 0.1f) {
        delta_time = 0.1f;
    }

    return delta_time;
}

bool IsQuit(void){

  return EngineQuit;
 
  
}

void EngineBeginFrame(void) {

for (int i = 0; i < SDL_SCANCODE_COUNT; i++)
{
    KeysPressed[i] = false;
    KeysReleased[i] = false;
}

while (SDL_PollEvent(&EngineEvent))
{
    switch (EngineEvent.type)
    {
        case SDL_EVENT_KEY_DOWN:
            KeysPressed[EngineEvent.key.scancode] = true;
            break;

        case SDL_EVENT_KEY_UP:
            KeysReleased[EngineEvent.key.scancode] = true;
            break;

        case SDL_EVENT_QUIT:
            EngineQuit = true;
            break;
    }
}
}
