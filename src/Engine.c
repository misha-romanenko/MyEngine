#include <Engine.h>
  

SDL_Window *EngineWindow = NULL;
SDL_Renderer *EngineRenderer = NULL;
SDL_Event EngineEvent;

bool KeysPressed[SDL_SCANCODE_COUNT];
bool KeysReleased[SDL_SCANCODE_COUNT];
bool KeysDown[SDL_SCANCODE_COUNT];
bool EngineQuit = false;


SDL_FRect GetFRectFromRect(Rect OriginalRect){
  
  

  SDL_FRect CopyFRect = {
    .x = OriginalRect.x,
    .y = OriginalRect.y,
    .w = OriginalRect.width,
    .h = OriginalRect.height
  };

  return CopyFRect;
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



void DrawBackground(Colour colour)
{
  SDL_SetRenderDrawColor(EngineRenderer, colour.Red, colour.Green, colour.Blue, colour.Alpha);

  SDL_RenderClear(EngineRenderer);

}

void FPSLimitSet(int fps_limit_value)
{

  int devided_fps_limit_value = 1000.0 / fps_limit_value;


  SDL_Delay((int)devided_fps_limit_value);

}


Texture *LoadTexture(const char *filepath){


  

  
  Texture *ReturnStruct = malloc(sizeof(Texture));;

  ReturnStruct->surface = IMG_Load(filepath);

  if (!ReturnStruct->surface)
  {
    SDL_Log("Omg an error: %s", SDL_GetError());
  }


  ReturnStruct->texture = SDL_CreateTextureFromSurface(EngineRenderer, ReturnStruct->surface);

  return ReturnStruct;
}

void EndDrawing(void)
{
    SDL_RenderPresent(EngineRenderer);
}

bool IsKeyDown(SDL_Scancode key)
{
    return SDL_GetKeyboardState(NULL)[key];
}

bool IsKeyPressed(SDL_Scancode key){



    return KeysPressed[key];


}

bool IsKeyReleased(SDL_Scancode key){

  return KeysReleased[key];

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

bool FreeTexture(Texture *texture)
{
  SDL_DestroyTexture(texture->texture);

  SDL_DestroySurface(texture->surface);
  
  free(texture);
}


