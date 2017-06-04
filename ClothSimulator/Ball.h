#ifndef Ball_h__
#define Ball_h__

#include "vec3.h"

typedef struct Ball
{
  vec3 position;
  float radius;
  int timeToLive;
  vec3 velocity;

}Ball;


void ball_AddBall(Ball* ballList, int* ballCount, int maxBalls, vec3 pos, vec3 vel, float rad, int ttl);

void ball_Remove(Ball* ballList, int* index, int* ballCount);

void ball_UpdateBalls(Ball* ballList, int* ballCount);

#endif // Ball_h__
