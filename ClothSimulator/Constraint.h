#ifndef Constraint_h__
#define Constraint_h__

#include "Particle.h"

/*******************************************************************************************************************************
* @file Constraint.h
* @author Maddisen Topaz
* @date S1, 2017
* @brief This constraint class contains all of the functions related to a constraint between two particles.
* @description
*
*******************************************************************************************************************************/


/**
*@brief The Constraint struct conntains all of the data to make a constraint between two particles.
*/
typedef struct Constraint
{
  //The two particles that are connected through this constraint
  Particle* p1;
  Particle* p2;

  float restDistance;

}Constraint;


/**
*@brief Initializes a constraint.
*@para Constraint* const constraint
*@return void
*/
void constraint_Init(Constraint* const constraint);


/**
*@brief Factors in constraints on the particles movement.
*Adjusts the cloth so that each constraint is satisfied.
*@para Constraint* const constraint
*@return void
*/
void constraint_Satisfy(Constraint* const constraint);


/**
*@brief Makes a constraint between two particles.
*@para Particle* p1, Particle* p2, float restDistance
*@return c
*/
Constraint constraint_Make(Particle* p1, Particle* p2, float restDistance);

#endif // Constraint_h__
