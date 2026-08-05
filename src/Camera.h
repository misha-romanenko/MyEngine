

// Camera.h

#ifndef CAMERA_H
#define CAMERA_H

typedef struct
{
    float x;
    float y;

    int width;
    int height;
} Camera;

void InitCamera(Camera *camera, int width, int height);

void CenterCameraOn(Camera *camera, float targetX, float targetY);

float WorldToScreenX(Camera *camera, float worldX);
float WorldToScreenY(Camera *camera, float worldY);

int IsVisible(Camera *camera,
              float x, float y,
              float width, float height);

#endif
