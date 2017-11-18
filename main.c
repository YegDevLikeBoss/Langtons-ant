#include <stdio.h>
#include <time.h>
#include <GL/freeglut.h>

#define SPACE 30

int WindW, WindH;
int i, mem, minus=-1;
int alpha;
int x=SPACE/2, y=SPACE/2, count=0, neg=-1, x_num=1, y_num=1, ii, jj;
static int tmx=0, tmy=0;

int space[SPACE][SPACE];

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





    glTranslated( ((double)tmx)/10000.0, ((double)tmy)/10000.0, 0);



        if (x<0)
            x=SPACE-1;
            else if (x>=SPACE)
                x=0;
        if (y<0)
            y=SPACE-1;
            else if (y>=SPACE)
                y=0;
        if (space[y][x]==0)
            space[y][x]=1;
            else
                space[y][x]=0;
        if (count==0)
        {
            count=1;
            y+=y_num;
            if (space[y][x]==0)
                x_num*=neg;

        } else

        if (count==1)
        {
            count=0;
            x+=x_num;
            if (space[y][x]==0)
                y_num*=neg;

       }

    tmx+=x_num;
    tmy+=y_num;


    printf("%d %d %d %d)", tmx, tmy, x_num, y_num);

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
  glutTimerFunc(10, timf, 0); /*Setup next timer*/
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


    for (ii=0;ii<SPACE;ii++)
        {
            for (jj=0;jj<SPACE;jj++)
            {
                space[ii][jj]=0;
            }
        }

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
