#ifndef COLLISION_H
#define COLLISION_H

#include "Shapes.h"
#include <stdbool.h>


bool IsCollision(Rect rect1, Rect rect2);

Rect GetCollisionRect(Rect rect1, Rect rect2);


#endif // !COLLISION_H

