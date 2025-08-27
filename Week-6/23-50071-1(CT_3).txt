
#include<cstdio>
#include <math.h>

#include <GL/gl.h>
#include <GL/glut.h>

#include <math.h>
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

GLfloat sunR = 0.0f;
GLfloat earthR = 0.0f;
GLfloat moonR =0.0f;
GLfloat sunOR =  0.1f;
GLfloat earthOR = 0.1f;
GLfloat moonOR =0.1f;


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

glPushMatrix();
//sun
glRotatef(sunR, 0.0f, 0.0f, 1.0f);
glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f( 0.2f, -0.2f);
      glVertex2f( 0.2f,  0.2f);
      glVertex2f(-0.2f,  0.2f);
glEnd();
glPopMatrix();

//earth
glPushMatrix();
        glRotatef(earthR, 0.0f, 0.0f, 1.0f);

        glPushMatrix();
        glRotatef(earthOR, 0.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS);

      glColor3f(0.2f, 0.0f, 0.8f);
      glVertex2f(0.7f, -0.1f);
      glVertex2f( 0.9f, -0.1f);
      glVertex2f( 0.9f,  0.1f);
      glVertex2f(0.7f,  0.1f);
      glEnd();
      glPopMatrix();



glPopMatrix();

glPushMatrix();
        glRotatef(moonR, 0.0f, 0.0f, 1.0f);

//moon
//glTranslatef(position,0.0f, 0.0f);
glPushMatrix();
        glRotatef(moonOR, 0.0f, 0.0f, 1.0f);
glTranslatef(0.0 ,0.0f, 0.0f);

glBegin(GL_QUADS);

      glColor3f(0.5f, 0.5f, 0.5f);
      glVertex2f(0.5f, -0.05f);
      glVertex2f( 0.6f, -0.05f);
      glVertex2f( 0.6f,  0.05f);
      glVertex2f(0.5f,  0.05f);
glEnd();

glPopMatrix();
glPopMatrix();





    glFlush();
}


void update(int value) {
    sunR += 0.5f;
    if (sunR > 360){
      sunR-= 360;
    }
    earthR += 0.5f;
    if (earthR > 360){
      earthR-= 360;
    }
    moonR += 0.7f;
    if (moonR > 360){
      moonR-= 360;
    }
    earthOR += 0.5f;
    if (earthOR > 360){
      earthOR-= 360;
    }
    moonOR += 0.5f;
    if (moonOR > 360){
      moonOR-= 360;
    }





    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1000, 800);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);


    glutTimerFunc(100, update, 0);

   glutMainLoop();
   return 0;
}


