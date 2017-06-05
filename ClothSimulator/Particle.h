#ifndef Particle_h__
#define Particle_h__

#include "vec3.h"
#include <cstdbool>


/*******************************************************************************************************************************
* @file Particle.h
* @author Caroline Chua
* @date S1, 2017
* @brief This particle class contains all of the functions related to a particle.
* @description
*
*******************************************************************************************************************************/

#define TIME_STEP2 0.5*0.5

/**
*@brief The Particle struct contains all of the data relating to a particle.
*
*/
typedef struct Particle
{
  vec3 pos;
  vec3 old_pos;
  vec3 acceleration;
  vec3 accumulated_normal;

  float mass;
  bool moveable;

}Particle;


/**
*@brief Initialise the particle.
*@para Particle* const a_particle
*@return void
*/
void particle_Init(Particle* const a_particle);


/**
*@brief Create particle pointer and memory allocation.
*@para Particle** const a_particlePointer
*@return void
*/
void particle_Create(Particle** const a_particlePointer);


/**
*@brief Adds a force to the particle.
* F = MA
* A = F / M
*@para Particle* const a_particle, vec3 a_vector
*@return void
*/
void particle_AddForce(Particle* const a_particle, vec3 a_vector);

/**
*@brief The particles update function.
*
*The next step is found through Newton's equations of motion.
*@para Particle* const a_particle, float dt, float last_dt, float damping
*@return void
*/
void particle_TimeStep(Particle* const a_particle, float damping);



/**
*@brief Set acceleration to zero.
*@para vec3* a_vector
*@return void
*/
void particle_ResetAcceleration(vec3* a_vector);

/**
*@brief Moves the particle.
*@para Particle* const a_particle, vec3 a_vector
*@return void
*/
void particle_Move(Particle* const a_particle, vec3 a_vector);

/**
*@brief Makes the particle unmoveable.
*@para Particle* const a_particle
*@return void
*/
void particle_MakeUnmoveable(Particle* const a_particle);

/**
*@brief Offsets the particle position.
*@para Particle* const a_particle, vec3 position
*@return void
*/
void particle_OffsetPosition(Particle* const a_particle, vec3 position);

#endif // Particle_h__
