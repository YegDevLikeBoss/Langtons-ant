#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>

int WindW, WindH;
int i, mem, minus=-1;
int alpha;
static int tmx=6, tmy=6;
int space[600][600];

void Reshape(int width, int height) /*Reshape function*/
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1, 1, -1, 1);
  glMatrixMode(GL_MODELVIEW);

  WindW = width;
  WindH = height;
}

void Draw(void) /*Window redraw function*/
{
  glClear(GL_COLOR_BUFFER_BIT);

  /*glLineWidth(3);*/
  glColor3f(0.0f, 0.0f, 0.0f);

  glPushMatrix();
  /*glRotatef(alpha, 0.0f, 1.0f, 0.0f);
  alpha += 4;
  if (alpha > 359) alpha = 0;*/
    tmx = rand() %100;
    tmy = rand() %100;
    minus = rand() %2;
    if (minus==1)
        tmx*=-1;
    minus = rand() %2;
    if (minus==1)
        tmy*=-1;
    glTranslated( ((double)tmx)/10000.0, ((double)tmy)/10000.0, 0);


    i++;
    printf("%d %d)", tmx,tmy);

  glBegin(GL_QUADS);
    glVertex2f(0.01f, 0.01f);
    glVertex2f(0.01f, -0.01f);
    glVertex2f(-0.01f, -0.01f);
    glVertex2f(-0.01f, 0.01f);
  glEnd();

  /*glPopMatrix();*/

  /*glFlush();*/
  glutSwapBuffers();
}

void Visibility(int state) /*Visibility function*/
{
  if (state == GLUT_NOT_VISIBLE) printf("Window not visible!\n");
  if (state == GLUT_VISIBLE) printf("Window visible!\n");
}

void timf(int value) /*Timer function*/
{
  glutPostRedisplay();  /*Redraw windows*/
  glutTimerFunc(50, timf, 0); /*Setup next timer*/
}

/*void matr()
{
    int i, j;
    for (i=0;i<600;i++)
    {
        for (i=0;i<600;i++)
        {
            p
        }
    }
}
*/
int main(int argc, char *argv[])
{
  WindW = 600;
  WindH = 600;
  alpha = 1;

    printf("aaaaaaaa");


  srand(time(NULL));
  glutInit(&argc, argv);
  glutInitWindowSize(WindW, WindH);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("Lengton's ant");

  glutReshapeFunc(Reshape); /*Set up reshape function*/
  glutDisplayFunc(Draw);    /*Set up redisplay function*/
  glutTimerFunc(100, timf, 0); /*Set up timer for 40ms, about 25 fps*/
  glutVisibilityFunc(Visibility); /*Set up visibility funtion*/
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  glutMainLoop();

  return 0;
}
