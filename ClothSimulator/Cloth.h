#ifndef Cloth_h__
#define Cloth_h__

#include "Particle.h"
#include "Constraint.h"
#include <stdlib.h>


typedef struct Cloth
{
  int numParticlesX;
  int numParticlesY;

  int width;
  int height;

  Particle* particles;
  Constraint* constraints;

}Cloth;

void cloth_Init(Cloth* const cloth, int width, int height, int a_numParticlesX, int a_numParticlesY)
{

}

void cloth_Create(Cloth* const cloth)
{

}

Particle* cloth_GetParticle(Cloth* const cloth, int x, int y)
{

}

void cloth_AddConstraints(Cloth* cloth)
{

}

#endif // Cloth_h__

