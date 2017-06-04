#include "Input.h"
#include "Ball.h"

float lastX;
float lastY;

vec3 translation;

void MouseMotion(int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    //Exit when the escape key is pressed.
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}


void arrow_keys(int a_keys, int x, int y)
{
  switch (a_keys)
  {
    //Switch in to full screen mode
  case GLUT_KEY_UP:
    glutFullScreen();
    break;
    //Switch to windowed mode
  case GLUT_KEY_DOWN:
    glutReshapeWindow(1280, 720);
    break;
  default:
    break;
  }
}