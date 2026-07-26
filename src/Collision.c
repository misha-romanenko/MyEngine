#include "Collision.h"


bool IsCollision(Rect rect1, Rect rect2)
{

  //

  if (rect1.x + rect1.width < rect2.x) { return false; }

  // 

  if (rect2.x + rect2.width < rect1.x) { return false; }

  // 

  if (rect1.y + rect1.height < rect2.y) { return false; }

  // 

  if (rect2.y + rect2.height < rect1.y) { return false; }

  // if nothing returned return true as a sign of collision
  
  return true;

}


Rect GetCollisionRect(Rect rect1, Rect rect2)
{

  Rect CollisionRect;

  // work has to be done with ts but i am tired ass 

  return CollisionRect;

}

