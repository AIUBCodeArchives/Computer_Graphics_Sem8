/*
* GL02Primitive.cpp: Vertex, Primitive and Color
* Draw Simple 2D colored Shapes: quad, triangle and polygon.
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}


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

void star(float radius, float xc, float yc, float r, float g, float b)
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

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
//Draw the square using GL_QUADS
glColor3f(0.5f, 0.5f, 0.5f); // Gray color
glBegin(GL_QUADS); // PRIMITIVE is GL_QUADS
glVertex2f(-0.5f, -0.5f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.5f, 0.5f);
glVertex2f(-0.5f, 0.5f);
glEnd();
// Draw a triangle using GL_LINE_LOOP
glColor3f(0.0f, 0.0f, 0.0f); // Black color
glBegin(GL_LINE_LOOP);
glVertex2f(0.5f, 0.5f);
glVertex2f(0.0f, 1.0f);
glVertex2f(-0.5f, 0.5f);
glEnd();
// Draw a diagonal line using GL_LINES
glColor3f(0.0f, 0.0f, 0.0f); // White color
glLineWidth(0.5f);
glBegin(GL_LINES);
glVertex2f(0.0f, -0.5f);
glVertex2f(0.0f, 1.0f);
glEnd();

	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
