#ifndef Ball_h__
#define Ball_h__

#include "vec3.h"


/**
*@brief The Ball struct stores information relating to the ball object. 
*/
typedef struct Ball
{
  vec3 position;
  float radius;
  int timeToLive;
  vec3 velocity;

}Ball;


/**
*@brief Used to add a new ball to the list of balls.
*@param Ball* ballList, int* ballCount, int maxBalls, vec3 pos, vec3 vel, float rad, int ttl
*@return void
*/
void ball_AddBall(Ball* ballList, int* ballCount, int maxBalls, vec3 pos, vec3 vel, float rad, int ttl);

/**
*@brief Removes a ball from the list of balls.
*@para Ball* ballList, int* index, int* ballCount
*@return void
*/
void ball_Remove(Ball* ballList, int* index, int* ballCount);

void ball_UpdateBalls(Ball* ballList, int* ballCount);

#endif // Ball_h__
