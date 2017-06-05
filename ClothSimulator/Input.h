#ifndef Input_h__
#define Input_h__


#include <stdio.h>
#include "vec3.h"
#include "gl/glew.h"
#include <GL/freeglut.h>
#include <GL/glut.h> 


/*******************************************************************************************************************************
* @file Input.h
* @author Maddisen Topaz , Matt Smooker, Caroline Chua
* @date S1, 2017
* @brief The input class contains all of the functions related to input handling.
* @description
*
*******************************************************************************************************************************/


/**
*@brief The keyboard input function to pass to GLUT.
*@para unsigned char key, int x, int y
*@return void
*/
void keyboard(unsigned char key, int x, int y);


/**
*@brief The keyboard input function to pass to GLUT that handles resizing the window.
*@para int a_keys, int x, int y
*@return void
*/
void arrow_keys(int a_keys, int x, int y);

#endif // Input_h__
