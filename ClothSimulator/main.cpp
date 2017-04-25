#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h> 
#include <math.h>


void display(void)
{
  //Clears the color and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  //Loading the identity matrix is a way to initialize your matrix to the right state 
  //before you multiply further matrices into the matrix stack
  glLoadIdentity();

  //If enabled, use the current lighting parameters to
  //compute the vertex color.
  //Otherwise, simply associate the current color with each vertex
  glEnable(GL_LIGHTING);

  glTranslatef(-6.5, 6, -9.0f);
  glRotatef(25, 0, 1, 0);

  //glutSwapBuffers swaps the buffers of the current window if double buffered
  glutSwapBuffers();
  //glutPostRedisplay marks the current window as needing to be redisplayed
  glutPostRedisplay();
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

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (h == 0)
    gluPerspective(80, (float)w, 1.0, 5000.0);
  else
    gluPerspective(80, (float)w / (float)h, 1.0, 5000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init(GLvoid)
{
  //GL primitives can have either flat or smooth shading.
  //Smooth shading,the default, causes the computed colors of vertices to be interpolated as the
  //primitive is rasterized, typically assigning different colors to each resulting pixel fragment.
  glShadeModel(GL_SMOOTH);

  //Specify the red, green, blue, and alpha values used when the color buffers are cleared.
  glClearColor(0.2f, 0.2f, 0.4f, 0.5f);
  glClearDepth(1.0f);

  //If enabled, do depth comparisons and update the depth buffer.
  glEnable(GL_DEPTH_TEST);

  //glDepthFunc specifies the function used to compare each incoming pixel depth value 
  //with the depth value present in the depth buffer. 
  //The comparison is performed only if depth testing is enabled.
  glDepthFunc(GL_LEQUAL);

  //If enabled, have one or more material parameters track the current color.
  glEnable(GL_COLOR_MATERIAL);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  GLfloat lightPos[4] = { -1.0,1.0,0.5,0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat *)&lightPos);

  glEnable(GL_LIGHT1);
  GLfloat lightAmbient1[4] = { 0.0,0.0,0.0,0.0 };
  GLfloat lightPos1[4] = { 1.0,0.0,-0.2,0.0 };
  GLfloat lightDiffuse1[4] = { 0.5,0.5,0.3,0.0 };

  glLightfv(GL_LIGHT1, GL_POSITION, (GLfloat *)&lightPos1);
  glLightfv(GL_LIGHT1, GL_AMBIENT, (GLfloat *)&lightAmbient1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, (GLfloat *)&lightDiffuse1);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(1280, 720);

  glutCreateWindow("Cloth Simulator");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrow_keys);

  glutMainLoop();
}



