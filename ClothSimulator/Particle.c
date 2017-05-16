#include "Particle.h"

void particle_Init(Particle* const a_particle)
{

	a_particle->pos.x = 0;		// Set current position of particle x variable to 0
	a_particle->pos.y = 0;		// Set current position of particle y variable to 0
	a_particle->pos.z = 0;		// Set current position of particle z variable to 0

	a_particle->old_pos.x = 0;	// Set old position of particle x variable to 0
	a_particle->old_pos.y = 0;	// Set old position of particle y variable to 0
	a_particle->old_pos.z = 0;	// Set old position of particle z variable to 0

	a_particle->accumulated_normal.x = 0;	// Set the accumulated normal of particle x variable to 0
	a_particle->accumulated_normal.y = 0;	// Set the accumulated normal of particle y variable to 0
	a_particle->accumulated_normal.z = 0;	// Set the accumulated normal of particle z variable to 0

	particle_ResetAcceleration(a_particle->acceleration); // Set the vector of the particle to 0

	a_particle->mass = 1;			// Set the mass of the particle to 0
	a_particle->moveable = true;	// Set the particle to movable.

} // End of particle_Init

void particle_Create(Particle** const a_particlePointer)
{

	// Create a block of memory the size of Particle and return a pointer to the location
	*a_particlePointer = (Particle*)malloc(sizeof(Particle));	

	// Initialise a particle at the specified memory location
	particle_Init(*a_particlePointer);

} // End of particle_Create


// F = MA
// A = F / M
void particle_AddForce(Particle* const a_particle, vec3 a_vector)
{

	vec3_Add(a_particle->acceleration, vec3_Divide(a_vector, a_particle->mass));

}// End of particle_AddForce


void particle_TimeStep(Particle* const a_particle, float dt, float last_dt, float damping)
{

	if (a_particle->moveable)
	{

		vec3 temp = a_particle->pos;

		// Initial velocity is found by subtracting current position from old position
		vec3 initVelocity = vec3_Subtract(a_particle->pos, a_particle->old_pos);

		float frameRatio = (dt / last_dt);		// Calculate the frame ratio
		vec3 normalVelocity = vec3_Multiply(initVelocity, frameRatio);		// Calculate the normal vector

		vec3 dampedVelocity = vec3_Multiply(normalVelocity, 1 - damping);	// Damp the velocity
		vec3 accelTimeSquared = vec3_Multiply(a_particle->acceleration, TIME_STEP2);

		vec3 finalPos = vec3_Add(a_particle->pos, dampedVelocity);		// Find the final position of the particle
		finalPos = vec3_Add(finalPos, accelTimeSquared);

		// Store the position in temp, and prepare for the next iteration
		a_particle->old_pos = temp;			
		particle_ResetAcceleration(a_particle->acceleration);

	} // End of if movable

} // End of particle_TimeStep


void particle_ResetAcceleration(vec3 a_vector)
{

	a_vector.x = 0;			// Resets a_vector's x variable to 0
	a_vector.y = 0;			// Resets a_vector's y variable to 0
	a_vector.z = 0;			// Resets a_vector's z variable to 0

} // End of particle_ResetAcceleration


void particle_Move(Particle* const a_particle, vec3 a_vector)
{

	vec3 newPos;				// Create a new position
	vec3_Init(&newPos);			// Initialise the new position
	newPos = a_particle->pos;	// Give the new position the particles coordinates
	newPos = vec3_Add(a_particle->pos, a_vector);	// Give the new position the particles velocity
	a_particle->pos = newPos;	// Assign the new position to the particle

} // End of particle_Move


void particle_MakeUnmoveable(Particle* const a_particle)
{

	a_particle->moveable = false;		// Make the particle unmoveable

} // End of particle_MakeUnmoveable