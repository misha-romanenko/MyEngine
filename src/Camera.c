#include "Camera.h"

void InitCamera(Camera *camera, int width, int height)
{
    camera->x = 0;
    camera->y = 0;
    camera->width = width;
    camera->height = height;
}

void CenterCameraOn(Camera *camera, float targetX, float targetY)
{
  camera->x = targetX - camera->width / 2.0f;
  camera->y = targetY - camera->height / 2.0f;
}


float WorldToScreenX(Camera *camera, float worldX)
{
    return worldX - camera->x;
}

float WorldToScreenY(Camera *camera, float worldY)
{
    return worldY - camera->y;
}
