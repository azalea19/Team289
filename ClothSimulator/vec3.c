
#include <stdlib.h>
#include <math.h>
#include "vec3.h"


void vec3_Init(vec3* const vector)
{

	vector->x = 0;
	vector->y = 0;
	vector->z = 0;

} // end of vec3_Init()


void vec3_Create(vec3** const vectorPointer)	
{

	*vectorPointer = (vec3*)malloc(sizeof(vec3));
	vec3_Init(*vectorPointer);

} // End of vec3_Create()


vec3 vec3_Add(vec3 vector1, vec3 vector2)
{

	vec3 sum;
	vec3_Init(&sum);

	sum.x = vector1.x + vector2.x;
	sum.y = vector1.y + vector2.y;
	sum.z = vector1.z + vector2.z;

	return sum;

} // End of vec3_Add()


vec3 vec3_Subtract(vec3 vector1, vec3 vector2)
{

	vec3 difference;
	vec3_Init(&difference);

	difference.x = vector1.x - vector2.x;
	difference.y = vector1.y - vector2.y;
	difference.z = vector1.z - vector2.z;

	return difference;

} // End of vec3_Subtract()


vec3 vec3_Multiply(vec3 vector, float multiplier)
{

	vec3 product;
	vec3_Init(&product);

	product.x *= multiplier;
	product.y *= multiplier;
	product.z *= multiplier;

	return product;

} // End of vec3_Multiply()


vec3 vec3_Divide(vec3 vector, float divisor)
{

	vec3 quotient;
	vec3_Init(&quotient);

	quotient.x /= divisor;
	quotient.y /= divisor;
	quotient.z /= divisor;

	return quotient;

} // End of vec3_Divide()


float vec3_Dot(vec3 vector1, vec3 vector2)
{

	vec3 product;
	vec3_Init(&product);

	product.x = vector1.x * vector2.x;
	product.y = vector1.y * vector2.y;
	product.z = vector1.z * vector2.z;

	return product.x + product.y + product.z;

} // End of vec3_Dot()


vec3 vec3_Cross(vec3 vector1, vec3 vector2)
{

	vec3 product;
	vec3_Init(&product);

	product.x = (vector1.y * vector2.z - vector1.z * vector2.y);
	product.y = (vector1.x * vector2.z - vector1.z * vector2.y);
	product.z = (vector1.x * vector2.y - vector1.y * vector2.x);

	return product;

} // End of vec3_Cross()


float vec3_Magnitude(vec3 vector)
{
	
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

} // End of vec3_Magnitude()


vec3 vec3_Normalise(vec3 vector)
{

	vec3 normalised;
	float magnitude = vec3_Magnitude(vector);

	normalised.x /= magnitude;
	normalised.y /= magnitude;
	normalised.z /= magnitude;

	return normalised;

} // End of vec3_Normalise()


