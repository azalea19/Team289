#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h> 
#include <math.h>


void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glEnable(GL_LIGHTING);

  glTranslatef(-6.5, 6, -9.0f);
  glRotatef(25, 0, 1, 0);

  glutSwapBuffers();
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 27:
      exit(0);
      break;
    default:
      break;
  }
}

void arrow_keys(int a_keys, int x, int y)
{
  switch (a_keys) {
    case GLUT_KEY_UP:
      glutFullScreen();
      break;
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
  glShadeModel(GL_SMOOTH);
  glClearColor(0.2f, 0.2f, 0.4f, 0.5f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_COLOR_MATERIAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

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



