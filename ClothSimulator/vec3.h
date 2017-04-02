
#ifndef vec3_h_
#define vec3_h_

typedef struct vec3
{
	float x, y, z;
} vec3;

/***************************************************************
* A void function that acts as a default constructor for vec3. *
***************************************************************/
void vec3_Init(vec3* const vector);


/***********************************************************************
* A function that is used like a constructor to create a vec3 pointer. *
***********************************************************************/
void vec3_Create(vec3** const vectorPointer);


/************************************************************************
* A function that takes in two vectors, adds them, and returns the sum. *
************************************************************************/
vec3 vec3_Add(vec3 vector1, vec3 vector2);


/************************************************************************************
* A function that takes in two vectors, subtracts them, and returns the difference. *
************************************************************************************/
vec3 vec3_Subtract(vec3 vector1, vec3 vector2);


/**************************************************************************
* A function that takes in a vector, multiplies it by the given number,   *
* and returns the product.                                                *
**************************************************************************/
vec3 vec3_Multiply(vec3 vector, float multiplier);


/*******************************************************************************
* A function that takes in a vector, divides it by the given divisor, and then *
* returns the quotient.														   *
*******************************************************************************/
vec3 vec3_Divide(vec3 vector, float divisor);


/*****************************************************************************
* A function that takes in two vectors, multiplies the two of them, and then *
* returns the sum of the products.											 *
*****************************************************************************/
float vec3_Dot(vec3 vector1, vec3 vector2);


/*******************************************************************************
* A function that takes in two vectors, calculates the cross product, and then *
* returns the product.														   *
*******************************************************************************/
vec3 vec3_Cross(vec3 vector1, vec3 vector2);


/***************************************************************************
* A function that calculates the length of a vector: sqrt(x^2 + y^2 + z^2) *
* and then returns the result.											   *
***************************************************************************/
float vec3_Magnitude(vec3 vector);


/******************************************************************************************
* A function that takes in a vector, calls the function vec3_Magnitude() to calculate the *
* magnitude of that vector, then uses this to normalise the vector before returning it.   *
******************************************************************************************/
vec3 vec3_Normalise(vec3 vector);



#endif // vec3_h_
