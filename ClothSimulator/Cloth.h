#ifndef Cloth_h__
#define Cloth_h__

#include "Particle.h"
#include "Constraint.h"
#include <stdlib.h>
#include "Input.h"
#include "Ball.h"


/*******************************************************************************************************************************
* @file Cloth.h
* @author Maddisen Topaz , Matt Smooker, Caroline Chua
* @date S1, 2017
* @brief The cloth class contains all of the functions related to the cloth structure.
* @description
*
*******************************************************************************************************************************/




extern int CLOTH_BANNER;
extern int CLOTH_CURTAIN;

static int lastCloth = 1;

/**
*@brief The cloth struct stores all of the data relating to the cloth. 
*/
typedef struct Cloth
{
  int numParticlesX;
  int numParticlesY;

  int width;
  int height;

  int numConstraints;

  Particle* particles;
  Constraint* constraints;

}Cloth;

/**
*@brief Initializes cloth, setting the particles and constraints pointers to null.
*@param Cloth** const cloth
*@return void
*/
void cloth_Init(Cloth** const cloth);



/**
*@brief Initialize and set width, height, a_numParticlesX, a_numParticlesY, constraints and numConstraints of the cloth.
*@param Cloth* const cloth, int width, int height, int a_numParticlesX, int a_numParticlesY
*@return void
*/
void cloth_Create(Cloth* const cloth, int width, int height, int a_numParticlesX, int a_numParticlesY);

/**
*@brief Gets the particle at position x,y.
*@para Cloth* const cloth, int x, int y
*@return cloth particles
*/
Particle* cloth_GetParticle(Cloth* const cloth, int x, int y);


/**
*@brief Generates the particles of the cloth.
*@para Cloth* cloth
*@return void
*/
void cloth_AddParticles(Cloth* cloth);


/**
*@brief Change cloth type to curtain cloth or banner cloth.
*@para Cloth* cloth, int clothType
*@return void
*/
void cloth_ChangeType(Cloth* cloth, int clothType);


/**
*@brief Generates the constraints of the cloth particles.
*Diagonal distance is sqrt(2) away.
*Link adjacent particles with constraints(distance 1 and sqrt(2) in the grid)
*Link further away particles with constraints (distance 2 and sqrt(4) in the grid)
*@para Cloth* cloth
*@return void
*/
void cloth_AddConstraints(Cloth* cloth);


/**
*@brief Gets the normal by taking the cross product of two vectors (the two edges of the triangle).
*@para Particle const* p1, Particle const* p2, Particle const* p3
*@return vec3_Cross
*/
vec3 cloth_CalculateFlatNormal(Particle const* p1, Particle const* p2, Particle const* p3);


/**
*@brief Calculate the wind force on a triangle.
*Multiply the force by the area of the triangle.
*a larger triangle will be more affected by a wind force.
*@para Particle* p1, Particle* p2, Particle* p3, vec3 direction
*@return void
*/
void cloth_AddWindForceOnTriangle(Particle* p1, Particle* p2, Particle* p3, vec3 direction);


/**
*@brief Draw triangle with a color.
*@para Particle const*  p1, Particle const* p2, Particle const* p3, vec3 color
*@return void
*/
void cloth_DrawTriangle(Particle const*  p1, Particle const* p2, Particle const* p3, vec3 color);



/**
*@brief Draws a smooth shaded cloth.
*@para Cloth* cloth, int lighting, vec3 color
*@return void
*/
void cloth_DrawShaded(Cloth* cloth, int lighting, vec3 color);


/**
*@brief Simulates a ball collision with cloth.
*Detects and resolves a collision of cloth with ball.
*The positions of the cloth's particles are compared to the ball, then adjusted.
*@para Cloth* cloth, Ball* ballList, int* ballCount
*@return void
*/
void cloth_BallCollision(Cloth* cloth, Ball* ballList, int* ballCount);


/**
*@brief The cloths update function.
*@para Cloth* cloth, Ball* ballLists, int* ballCount, int constraintIterations
*@return void
*/
void cloth_TimeStep(Cloth* cloth, Ball* ballLists, int* ballCount, int constraintIterations);


/**
*@brief Adds a force to particles.
*@para Cloth* cloth, vec3 direction
*@return void
*/
void cloth_AddForce(Cloth* cloth, vec3 direction);

/**
*@brief Add wind forces to particles.
*Wind force is added for every triangle.
*@para Cloth* cloth, vec3 direction
*@return void
*/
void cloth_WindForce(Cloth* cloth, vec3 direction);

#endif // Cloth_h__
