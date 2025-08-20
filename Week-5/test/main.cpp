#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;



float _move = 0.0f;



void update1(int value) {

 _move += .02;
if(_move > 1.3)
{
_move = -1.0;
}
glutPostRedisplay();
glutTimerFunc(20, update1, 0);


}

void update2(int value) {

 _move -= .02;
if(_move < -1.3)
{
_move = 1.0;
}
glutPostRedisplay();
glutTimerFunc(20, update2, 0);


}
void drawRedBox() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3d(1,0,0);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);



 glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.5f, 0.0f);
glVertex2f(0.5f, 0.2f);
glVertex2f(0.1f, 0.2);
glEnd();
glPopMatrix();



glutSwapBuffers();



}

void drawGreenBox() {
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity(); //Reset the drawing perspective
glMatrixMode(GL_MODELVIEW);



 glPushMatrix();
glTranslatef(_move, 0.0f, 0.0f);


glBegin(GL_QUADS);
glColor3d(0,1,0);

glVertex2f(-0.1f, 0.2f);
glVertex2f(-0.5f, 0.2f);
glVertex2f(-0.5f, 0.4f);
glVertex2f(-0.1f, 0.4f);
glEnd();
glPopMatrix();


glutSwapBuffers();



}



int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 800);
glutCreateWindow("Transformation");

/*
glutDisplayFunc(drawRedBox);
glutTimerFunc(20, update1, 0);
*/
glutDisplayFunc(drawGreenBox);
glutTimerFunc(20, update2, 0);












glutMainLoop();
}
