#include "Ball.h"



void ball_AddBall(Ball* ballList, int* ballCount, int maxBalls, vec3 pos, vec3 vel, float rad, int ttl)
{
  if (*ballCount < maxBalls)
  {
    ballList[*ballCount].position = pos;
    ballList[*ballCount].radius = rad;
    ballList[*ballCount].timeToLive = ttl;
    ballList[*ballCount].velocity = vel;
    (*ballCount)++;
  }
}

void ball_Remove(Ball* ballList, int* index, int* ballCount)
{
  //A remove swap last
  //Get the last element and copy its data
  if ((*ballCount) > 0)
  {
    //Set the ball at index to the last element data we just copied
    ballList[*index].position = ballList[(*ballCount) - 1].position;
    ballList[*index].radius = ballList[(*ballCount) - 1].radius;
    ballList[*index].timeToLive = ballList[(*ballCount) - 1].timeToLive;
    ballList[*index].velocity = ballList[(*ballCount) - 1].velocity;
    (*ballCount)--;
  }
}

void ball_UpdateBalls(Ball* ballList, int* ballCount)
{
  for (int i = 0; i < (*ballCount); i++)
  {
    ballList[i].position = vec3_Add(ballList[i].position, ballList[i].velocity);
    ballList[i].timeToLive--;

    if (ballList[i].timeToLive <= 0)
    {
      ball_Remove(ballList, &i, ballCount);
    }
  }
}
