#ifndef Particle_h__
#define Particle_h__

#include "vec3.h"
#include <cstdbool>

#define TIME_STEP2 0.5*0.5


typedef struct Particle
{
  vec3 pos;
  vec3 old_pos;
  vec3 acceleration;
  vec3 accumulated_normal;

  float mass;
  bool moveable;

}Particle;

void particle_Init(Particle* const a_particle);


void particle_Create(Particle** const a_particlePointer);


// F = MA
// A = F / M
void particle_AddForce(Particle* const a_particle, vec3 a_vector);


void particle_TimeStep(Particle* const a_particle, float dt, float last_dt, float damping);


void particle_ResetAcceleration(vec3 a_vector);


void particle_Move(Particle* const a_particle, vec3 a_vector);


void particle_MakeUnmoveable(Particle* const a_particle);


#endif // Particle_h__
