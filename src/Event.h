#ifndef EVENT_H
#define EVENT_H

#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_Event EngineEvent;

extern bool EngineQuit;

float GetFrameTime(void);

bool IsQuit(void);

void EngineBeginFrame(void);

void EngineDestroy(void);

int EngineInit(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char *WINDOW_LABLE);

void FPSLimitSet(int fps_limit_value);
   

#endif // !EVENT_H

