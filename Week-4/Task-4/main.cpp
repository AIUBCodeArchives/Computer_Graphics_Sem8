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

    circle(0.8,0,0,0.0,0.0,0.0);
    circle(0.78,0,0,1.0,1.0,1.0);


    glLineWidth(3);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.8f, 0.1f);    // x, y
	glVertex2f(-0.45f, 0.45f);    // x, y
  // x, y
	glVertex2f(-0.45f, 0.45f);   // x, y
	glVertex2f(-0.45f, 0.25f);

	   // x, y
	glVertex2f(-0.45f, 0.25f);   // x, y
	glVertex2f(-0.4f, 0.2f);

	glVertex2f(-0.45f, 0.45f);    // x, y
	glVertex2f(-0.35f, 0.4f);    // x, y


	glVertex2f(-0.35f, 0.4f);    // x, y
	glVertex2f(0.0f, 0.6f);    // x, y
    // x, y

	glVertex2f(0.0f, 0.6f);     // x, y
	glVertex2f(0.0f, 0.4f);
	     // x, y
	glVertex2f(0.0f, 0.4f);      // x, y
	glVertex2f(0.2f, 0.2f);
	     // x, y
	//glVertex2f(0.2f, 0.2f);     // x, y
	//glVertex2f(0.1f, 0.1f);

	glVertex2f(0.0f, 0.6f);    // x, y
	glVertex2f(0.35f, 0.4f);    // x, y


	glVertex2f(0.35f, 0.4f);    // x, y
	glVertex2f(0.5f, 0.5f);    // x, y


	glVertex2f(0.5f, 0.5f);    // x, y
	glVertex2f(0.8f, 0.1f);    // x, y

	glEnd();

	//trees
	glLineWidth(3);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.0f, -0.8f);    // x, y
	glVertex2f(0.0f, -0.3f);    // x, y

	   //branch
	glVertex2f(0.0f, -0.3f);
	glVertex2f(-0.05f, -0.4f);

	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.05f, -0.4f);

	glVertex2f(0.0f, -0.4f);
	glVertex2f(-0.1f, -0.55f);

	glVertex2f(0.0f, -0.4f);
	glVertex2f(0.1f, -0.55f);

	glVertex2f(0.0f, -0.5f);
	glVertex2f(-0.15f, -0.7f);

	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.15f, -0.7f);


	glVertex2f(0.0f, -0.6f);
	glVertex2f(-0.15f, -0.75f);

	glVertex2f(0.0f, -0.6f);
	glVertex2f(0.15f, -0.75f);
	glEnd();

	//trees
	glLineWidth(3);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.0f, -0.8f);    // x, y
	glVertex2f(0.0f, -0.3f);    // x, y

	   //branch
	glVertex2f(0.0f, -0.3f);
	glVertex2f(-0.05f, -0.4f);

	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.05f, -0.4f);

	glVertex2f(0.0f, -0.4f);
	glVertex2f(-0.1f, -0.55f);

	glVertex2f(0.0f, -0.4f);
	glVertex2f(0.1f, -0.55f);

	glVertex2f(0.0f, -0.5f);
	glVertex2f(-0.15f, -0.7f);

	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.15f, -0.7f);


	glVertex2f(0.0f, -0.6f);
	glVertex2f(-0.15f, -0.75f);

	glVertex2f(0.0f, -0.6f);
	glVertex2f(0.15f, -0.75f);
	glEnd();

	//camp
	glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(0.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.5f, -0.2f);    // x, y
	glVertex2f(0.6f, -0.2f);    // x, y

	glVertex2f(-0.3f, -0.2f);    // x, y
	glVertex2f(-0.1f, 0.2f);

	   // x, y
	glVertex2f(-0.1f, 0.2f);    // x, y
	glVertex2f(0.1f, -0.2f);   // x, y


	glVertex2f(-0.1f, 0.2f);
	glVertex2f(0.3f, 0.2f);


	glVertex2f(0.3f, 0.2f);
	glVertex2f(0.5f, -0.2f);




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
