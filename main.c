#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <Gl/freeglut.h>

void myinit(void) {
glClearColor(0.5, 0.5, 0.5, 0.0);
glColor3f(1.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 480.0, 0.0, 640.0);
glMatrixMode(GL_MODELVIEW);
}

void display(void) {
typedef GLfloat point2[2];
point2 vertices[3] = {{0.0, 0.0}, {240.0, 640.0}, {480.0, 0.0}};
int j, k;
point2 p = {0.0, 0.0};
glClear(GL_COLOR_BUFFER_BIT);
for (k = 0; k < 500000; k++) {
j = rand() % 3;
p[0] = (p[0] + vertices[j][0]) / 2.0;
p[1] = (p[1] + vertices[j][1]) / 2.0;
glBegin(GL_POINTS);
glVertex2fv(p);
glEnd();
}
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Langton's ant");
glutDisplayFunc (display);
myinit();
glutMainLoop();

return 0;
}
